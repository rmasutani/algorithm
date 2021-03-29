#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 10010;

// 二分探索バージョン
int N, S;
int A[NMAX];

int sum[NMAX];

void solve() {
    for (int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + A[i];
    }

    if (sum[N] < S) {
        cout << "0" << endl;
    }

    int res = N;
    for (int s = 0; sum[s] + S <= sum[N]; s++) {
        int t = lower_bound(sum+S, sum+N, sum[s] + S) - sum;
        res = min(res, t-s);
    }

    cout << res << endl;
}