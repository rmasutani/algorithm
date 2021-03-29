#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++) 
using namespace std;
using ll = long long;
const int NMAX = 1000000;

int main(void) {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> is_prime(N, 1);
    rep(i, N) {
        cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    // rep(i, N) {
    //     cout << A[i] << endl;
    // }

    rep(i, N) {
        if (!(is_prime[i])) continue;
        for(int j = i+1; j < N; j++) {
            if (A[j] % A[i] == 0) {
                is_prime[j] = 0;
                is_prime[i] = (int)!(A[i] == A[j]);
            }
        }
    }

    int ans = 0;
    rep(i, N) {
        ans += is_prime[i];
    }

    cout << ans << endl;

    return 0;
}
