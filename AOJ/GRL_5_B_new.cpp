#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000;
int depth[MAX][MAX];

using Graph = vector<vector<pair<int, int>>>;

void dfs(const Graph &G, int v, int p, const int &origin, const int &dest, int d = 0)
{
    if (depth[origin][v] < 0) {
        depth[origin][v] = d;
        depth[v][origin] = d; 
    }
    

    for (auto c: G[v]) {
        if (c.first == p) continue;
        dfs(G, c.first, v, origin, dest, d+c.second); 
    }
}

int main()
{
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(make_pair(t, w));
        G[t].push_back(make_pair(t, w));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                depth[i][j] = 0;
                continue;
            }
            depth[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (depth[i][j] < 0) {
                dfs(G, i, -1, i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int max_depth = -1;
        for (int j = 0; j< N; j++) {
            max_depth = max(max_depth, depth[i][j]);
        }
        cout << max_depth << endl;
    }

    return 0;
}