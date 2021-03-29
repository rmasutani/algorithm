#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const ll mod = 1e9+7LL;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll comb(ll a, ll b){
    ll x = 1;
    ll y = 1;
    for(int i = 0; i < b; i++){
        x *= a-i;
        x %= mod;
    }
    for(int i = 0; i < b; i++) {
        y *= i+1;
        y %= mod;
    }

    y = mod_pow(y,mod-2,mod);

    return x*y%mod;
}

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    ll ans = 0;
    for (int i = 1; i < M; i++) {
        ans += i * (M - i) * (N * N);
    }

    for (int i = 1; i < N; i++) {
        ans += i * (N - i) * (M * M);
    }

    ll pat = comb(N*M-2, K-2);
    ans += pat;

    cout << ans % mod << endl;

    return 0;
}