#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using ll = long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
vector<vector<int>> G;
const long long INF = 1LL << 60;

int main(void) {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<long long> dist(N, INF);
    dist[0] = 0;

    // (dist[v], v) で管理
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> que;
    que.push(make_pair(dist[0], 0));

    vector<int> ans(N, -1);
    while(!que.empty()) {
        long long d = que.top().first;
        int v = que.top().second;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e: G[v]) {
            // 距離は常に1
            if (chmin(dist[e], dist[v]+1)) {
                que.push(make_pair(dist[e], e));
                ans[e] = v;
            }
        }
    }    

    // 結果出力
    for (int v = 0; v < N; ++v) {
        // if (dist[v] < INF) cout << dist[v] << endl;
        // else cout << "INF" << endl;

        if (dist[v] == INF) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int v = 1; v < N; ++v) {
        cout << ++ans[v] << endl;
    }


    return 0;
}