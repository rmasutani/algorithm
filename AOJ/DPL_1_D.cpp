#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 100000;
int N, A[NMAX+1], L[NMAX];

int lis() {
    L[0] = A[0];
    int length = 1;

    for (int i = 0; i < N; i++) {
        if (L[length-1] < A[i]) {
            L[length++] = A[i];
        } else {
            *lower_bound(L, L + length, A[i]) = A[i];
        }
    }

    return length;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << lis() << endl;
    return 0;
}