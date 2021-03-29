#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int HMAX = 201;
const int WMAX = 201;
const int N = 10;
const int INF=1001001001;
int A[HMAX][WMAX];


template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main(void) {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> dp(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            // cout << A[i][j] << endl;
        }
    }

    // floyd warshall
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
    
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (A[i][j] == -1 || A[i][j] == 1) continue;
            // cout << A[i][j] << endl;
            ans += dp[A[i][j]][1];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " "; 
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;

    return  0;
}