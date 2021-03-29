#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to;
    int weight;
    int height;
    Edge(int to, int weight, int height) : to(to), weight(weight), height(height) {}
};

using Graph = vector<vector<Edge>>;

int dfs(int v, int p, Graph &G)
{
    int len = 0;
    for (auto& e: G[v])
    {
        if (e.to == p) continue;

        if (e.height == -1)
        {
            e.height = dfs(e.to, v, G);
        }
        len = max(len, e.weight + e.height);
    }
    return len;
}

int main()
{
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; ++i)
    {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w, -1));
        G[t].push_back(Edge(s, w, -1));
    }
    
    vector<int> hs(N);
    for (int i = 0; i < N; ++i)
    {
        hs[i] = dfs(i, -1, G);
        cout << hs[i] << endl;
    }

    return 0;
}

