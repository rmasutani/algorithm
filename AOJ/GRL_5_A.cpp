#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10000;
int memo[MAX][MAX];
struct Edge {
    int t;
    int w;
    Edge(int t, int w) : t(t), w(w) {}
};

using Graph = vector<vector<Edge>>;
Graph G;

// u: 訪問中の頂点, v: 
int dfs(int v, int p)
{
    int result = 0;
    // 隣接頂点の探索
    for (auto& next_v: G[v])
    {
        if (next_v.t == p) continue;

        if (memo[v][next_v.t] == -1) memo[v][next_v.t] = dfs(next_v.t, v);

        result = max(result, memo[v][next_v.t]+next_v.w);
    }

    return result;
}

int main() 
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            memo[i][j] = -1;
        }
    }

    G.assign(N, vector<Edge>());

    for (int i = 0; i < N-1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    for (int i = 0; i < N; i++) {
        cout << dfs(i, -1) << endl;
    }

    return 0;
}