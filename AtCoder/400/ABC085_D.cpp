#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 100010;
const int HMAX = 1000000010;
const int INF=1001001001;

using ll = long long;

int dp[NMAX][HMAX];
vector<int> a;
vector<int> b;

int main() {
    int N, H;
    cin >> N >> H;
    // dp.assign(N+1, vector<int>(H+1, INF));
    a.resize(N);
    b.resize(N);

    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];

    // for (int i = 0; i <= N; i++) dp[i][0] = 0;
    // for (int i = 0; i <= H; i++) dp[0][i] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= H; j++) {
            // 2通りの遷移
            if (a[i-1] >= j || b[i-1] >= j) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = dp[i-1][j];

            if (j - a[i-1] >= 0) dp[i][j] = min(dp[i][j], dp[i][j-a[i-1]]+1);

            if (j - b[i-1] >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-b[i-1]]+1);
        }
    } 

    // print
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= H; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[N][H] << endl;


    return 0;
}
