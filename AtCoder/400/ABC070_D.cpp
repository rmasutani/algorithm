#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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

// void printVector(vector<ll> &arr) {
//     for (int i = 0; i < (int)arr.size(); ++i) {
//         if (i) cout << " ";
//         cout << arr[i];
//     }
//     cout << endl;
// }

void dijkstra(const Graph &G, vector<ll> &dist, int x) {
    dist[x] = 0;

    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> que;
    que.push(make_pair(dist[x], x));

    while (!que.empty()) {
        // printVector(dist);
        long long d = que.top().first;
        int v = que.top().second;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e: G[v]) {
            // cout << e.w << endl;
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    } 
}


int main(void) {
    int N, Q, K;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a-1].push_back(Edge(b-1, c));
        G[b-1].push_back(Edge(a-1, c));
    }

    cin >> Q >> K;
    vector<pair<int, int>> query;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        query.push_back(make_pair(x-1, y-1));
    }

    // 最短距離計算の前計算
    vector<ll> dist(N, INF);
    dijkstra(G, dist, K-1);

    for (int i = 0; i < Q; i++) {
        ll min_dist;
        min_dist = dist[query[i].first] + dist[query[i].second];
        cout << min_dist << endl;
    }
    
    
    return 0;
}