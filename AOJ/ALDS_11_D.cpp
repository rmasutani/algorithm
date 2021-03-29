#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int L; cin >> L;
    for (int i = 0; i < L; ++i) {
        int s, t; cin >> s >> t;

        vector<int> dist(N, -1); 
        queue<int> que; 
        dist[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int nv: G[v]) {
                if (dist[nv] != -1) continue; 

                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }

        if (dist[t] != -1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
    // for (int v = 0; v < N; ++v) cout << v<< ": " << dist[v] << endl;
}