#include <iostream>
using ll = long long;
const int MAX_N = 10000000;

int N, L[MAX_N];

int main() {
    ll ans = 0;
    
    while (N > 1) {
        int mil1 = 0;
        int mil2 = 1;
        if (L[mil1] > L[mil2]) std::swap(mil1, mil2);

        for (int i = 2; i < N; i++) {
            if (L[i] < L[mil1]) {
                mil2 = mil1;
            }
            else if (L[i] < L[mil2]) {
                mil2 = i;
            }
        }

        int t = L[mil1] + L[mil2];
        ans += t;

        if (mil1 == N-1) std::swap(mil1, mil2);
        L[mil1] = t;
        L[mil2] = L[N-1];
        N--;
    }
}