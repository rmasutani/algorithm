#include <iostream>
#include <vector> 
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++) 
using namespace std;
using ll = long long;

vector<int> A;

int main() {
    int N;
    cin >> N;
    A.resize(N);
    rep(i, N) {
        cin >> A[i];
    }
    std::sort(A.rbegin(), A.rend());
    ll ans = 0;

    return 0;
}