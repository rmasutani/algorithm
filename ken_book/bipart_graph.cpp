#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
bool ans = true;

// my version
void dfs(const Graph& G, int v, int c) {
    color[v] = c;

    for (auto next_v: G[v]) {
        // 次の隣接頂点が訪問済みかつ色が違えばスキップ
        if (color[next_v] != -1 && color[next_v] != c) continue;

        // 現在訪問中の頂点と隣接している頂点の色が同じ場合、二部グラフではない
        if (color[next_v] != -1 && color[next_v] == c) {
            ans = false;
            continue;
        }

        if (c == 0) c = 1; 
        else c = 0;
        dfs(G, next_v, c);
    }
}

// けんちょんバージョン
bool isBipartite(const Graph &G, int v, int cur = 0) {
    color[v] = cur;

    for (const auto& next_v : G[v]) {
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false;
            continue;
        }

        if (!isBipartite(G, next_v, 1-cur)) return false;
    }

    return true;
}


int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.resize(N, -1);



    return 0;
}