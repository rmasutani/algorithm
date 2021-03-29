#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;
const int HMAX = 1000;
const int WMAX = 1000;

// 移動のパターン
const int mod = 1e9+7;
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};

int H, W;
vector<vector<int>> G;


int dp[HMAX][WMAX];
int rec(int h, int w) {
    if (dp[h][w] != -1) return dp[h][w];

    int res = 1;
    // 全ての移動パターン
    for (int i = 0; i < 4; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nh > H-1 || nw < 0 || nw >W-1) continue;

        if (G[nh][nw] > G[h][w]) res = (res + rec(nh, nw)) % mod;
    }

    return dp[h][w] = res % mod;
}

int main(void) {
    cin >> H >> W;
    G.assign(H, vector<int>(W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }


    // memo initialize
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++) {
            ans = (ans + rec(i, j)) % mod;
        }
    }

    cout << ans % (1000000000 + 7) << endl;


    return 0;
}