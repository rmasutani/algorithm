#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++) 
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 1; i < N+1; i++) {
        int div = N / i;
        ans += (ll)div*(div+1)/2; 
    }

    cout << ans << endl;
    return 0;
}