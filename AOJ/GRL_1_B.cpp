#include <iostream>
#include <algorithm>
#include <vector>
using ll = long long;
using namespace std;
const long long INF = 1LL << 50;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}


int main(void) {
    int N, M, s;
    cin >> N >> M >> s;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(Edge(b, c)); // 重みの正負を反転
    }


    bool exsit_negative_cycle = false;
    vector<long long> dist(N, INF);
    dist[s] = 0; // 始点は0
    for (int iter = 0; iter < N; ++iter) {
        bool update = false;
        for (int v = 0; v < N; ++v) {
            if (dist[v] == INF) continue;

            for (auto e: G[v]) {
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                    // if (e.to == N-1 && iter == N-1) exsit_negative_cycle = true;
                }
            }
        }

        if (!update) break;

        if (iter == N-1 && update) exsit_negative_cycle = true;
    }

    // if (exsit_negative_cycle) cout << "inf" << endl;
    // else {
    //     if (dist[N-1] < INF) cout <<  dist[N-1]*(-1) << endl;
    //     else cout << "inf" << endl;
    // }

    // 到達不可能なものは取り除かないといけない！

    if (exsit_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int i = 0; i < N; i++) {
            if (dist[i] < INF) cout <<  dist[i] << endl;
            else cout << "INF" << endl;
        }
    }

    return 0;
} 