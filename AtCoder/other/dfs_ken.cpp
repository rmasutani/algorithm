#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> visited;
vector<int> first_order;
vector<int> last_order;

void dfs(const Graph &G, int v, int& first_ptr, int& last_ptr) { // Pass by reference / value
    first_order[v] = first_ptr++;

    visited[v] = true;
    for (auto next_v: G[v]) {
        if (visited[next_v]) continue;
        dfs(G, next_v, first_ptr, last_ptr);
    }

    last_order[v] = last_ptr++;
}

int main() {
    int N, M; cin >> N >>M;

    Graph G(N);
    for ( int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visited.assign(N, false);
    first_order.resize(N);
    last_order.resize(N);
    int first_ptr = 0, last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);

    for (int v = 0; v < N; ++v)
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}

