#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int> >;

vector<bool> visited;
vector<int> order;

void dfs(const Graph &G, int v)
{
    visited[v] = true;
    for (auto next_v: G[v]) {
        if (visited[next_v]) continue;
        dfs(G, next_v);
    }

    order.push_back(v);
}

int main() 
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }

    visited.assign(N, false);
    
    for (int v = 0; v < N; v++) {
        if (visited[v]) continue;
        dfs(G, v);
    }

    std::reverse(order.begin(), order.end());

    for (int i = 0; i < N; i++) {
        cout << order[i] << endl;
    }

    return 0;
}