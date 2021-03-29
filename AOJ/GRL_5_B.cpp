#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> memo;
vector<vector<bool>> hasCalled;

struct Edge {
    int t;
    int w;
    Edge(int t, int w) : t(t), w(w) {}
};

using Graph = vector<vector<Edge>>;

// u: 訪問中の頂点, v: 
int dfs(const Graph &G, int v, int p)
{
    int result = 0;
    // 隣接頂点の探索
    for (auto next_v: G[v])
    {
        if (next_v.t == p) continue;

        if (!hasCalled[v][next_v.t])
        {
            memo[v][next_v.t] = dfs(G, next_v.t, v);
            hasCalled[v][next_v.t] = true;
        }

        result = max(result, memo[v][next_v.t]+next_v.w);
    }

    return result;
}

int main() 
{
    int N;
    cin >> N;
    Graph G(N);
    memo.assign(N, vector<int>(N, -1));
    hasCalled.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N-1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    for (int i = 0; i < N; i++)
    {
        cout << dfs(G, i, -1) << endl;
    }

    return 0;
}