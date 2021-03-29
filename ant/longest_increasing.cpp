#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 100001;
using ll = long long;

int main(void) {
    int N;
    cin >> N;
    ll dp[NMAX];
    for (int i = 0; i < N; i++) cin >> dp[i];

    pair<int, int> memo = make_pair(1, dp[0]);

    for (int i = 1; i < N; i++) {
        if (dp[i] > memo.second) {
            memo = make_pair(memo.first+1, dp[i]);
        } else {
            memo = make_pair(memo.first, dp[i]);
        }
    }

    cout << memo.first << endl;

    return 0;

}