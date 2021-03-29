#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
Graph G;
vector<bool> visited;

void dfs(int v) { // Pass by reference / value
    visited[v] = true;
    for (auto next_v: G[v]) {
        if (visited[next_v]) continue;
        dfs(next_v);
    }
}


int main(void) {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }

    visited.assign(N, false);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            ans += 1;
        }
    }

    cout << ans << endl;
    
    return 0;
}