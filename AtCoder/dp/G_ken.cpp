#include <iostream>
#include <vector>
using namespace std; 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

int N, M;
vector<vector<int>> G;

// メモ化再帰
int dp[100100];
int rec(int v) {
    if (dp[v] != -1) return dp[v];

    int res = 0;
    for (auto nv: G[v]) {
        chmax(res, rec(nv)+1);
    }

    return dp[v] = res; // ここでメモ化しながらリターン！！
}

int main(void) {
    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        G[x-1].push_back(y-1);
    }

    for (int v = 0; v < N; v++) dp[v] = -1;

    int res = 0;
    for (int v = 0; v < N; ++v) chmax(res, rec(v));

    
    cout << res << endl;

    return 0;
}