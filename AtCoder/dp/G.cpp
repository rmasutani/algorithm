#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1001001001;

int main(void) {
    int N, M;
    cin >> N >> M;

    // pair(to, weight)
    vector<vector<int>> dp(N, vector<int>(N, INF));

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        dp[x-1][y-1] = -1;
    }

    for (int i = 0; i < N; i++) dp[i][i] = 0;

    // floyd warshall
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
    
    // printしてみる
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 各行の最小値を求める
    int ans = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = min(ans, *min_element(dp[i].begin(), dp[i].end()));
        }
    }

    cout << -ans << endl;

    return 0;
} 