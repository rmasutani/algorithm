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
    int res = N+1;
    int s = 0, t = 0, sum = 0;

    for (;;) {
        while (t < N && sum < S) {
            sum += A[t++];
            if (sum < S) break;
            res = min(res, t-s);
            sum -= A[s++];
        }

        if (res > N) res - 0;
    }

    printf("%d\n", res);

}

int main() {
    solve();
}