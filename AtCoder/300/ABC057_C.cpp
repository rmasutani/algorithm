#include <iostream>
#include <math.h>
using ll = long long;
using namespace std;

int main() {
    ll N;
    cin >> N;

    int start = floor(sqrt(N));

    for (ll i = start; i < N+1; i++) {
        if (N%i == 0) {
            cout << floor(log10(i)+1) << endl;
            break;
        }
    }

    return 0;
}