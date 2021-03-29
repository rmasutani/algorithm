#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    int w;
    Edge (int to, int w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

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

void combinations(vector<int>& r) {
    
}

int main(void) {
    int N, M, R;
    cin >> N >> M >> R;
    Graph G(N);
    vector<int> r(R);
    for (int i = 0; i < R; ++i) cin >> r[i];

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a-1].push_back(Edge(b-1, c));
        G[b-1].push_back(Edge(a-1, c));
    }




    return 0;
}