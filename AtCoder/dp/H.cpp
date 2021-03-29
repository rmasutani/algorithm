#include <iostream>
#include <vector>
using namespace std; 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;
const int HMAX = 1000;
const int WMAX = 1000;

int H, W;
vector<vector<char>> A;
vector<vector<int>> dp;

int main(void) {
    cin >> H >> W;
    A.assign(H, vector<char>(W));
    dp.assign(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] == '.') dp[i+1][j+1] = 1;
            else dp[i+1][j+1] = 0;
        }
    } 

    for (int h = 1; h < H+1; h++) {
        for (int w = 1; w < W+1; w++) {
            if ((h==1 && w==1)|| A[h-1][w-1] == '#') continue;

            // 上と左を確認
            if (dp[h-1][w] == 0 && dp[h][w-1] == 0) dp[h][w] = 0;
            else dp[h][w] = dp[h-1][w]% (1000000000 + 7) + dp[h][w-1]% (1000000000 + 7);
        }
    }

    cout << dp[H][W] % (1000000000 + 7) << endl;

    return 0;
}