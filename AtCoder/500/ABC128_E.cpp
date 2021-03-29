#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++) 
using namespace std;
using ll = long long;
const int NMAX = 2 * 100010;
const int QMAX = 2 * 100010;

int T[2*NMAX] = {0};

int main() {
    int N, Q;
    cin >> N >> Q;
    rep(i, N) {
        int s, t, x;
        cin >> s >> t >> x;
        for (int i = 2*s-1; i < 2*t-1; i++) T[i] = x;
    }

    rep(i,Q) {
        int D; cin >> D;
        D *= 2;
        int ans = 0;
        int cur_x = 0;
        for (int i=D; i < 2*NMAX; i++) {

        }
    }

    return 0;
}