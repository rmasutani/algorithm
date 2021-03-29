#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 40;
const int COST_MAX_SUM = 40 * 100;
int A[NMAX], B[NMAX], C[NMAX];
int dp_a[NMAX+1][COST_MAX_SUM+1], dp_b[NMAX+1][COST_MAX_SUM+1];

void printArray(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

    int cost_max = 0;
    for (int i = 0; i < N; i++) cost_max += C[i];

    // DP
    for (int i = 0; i < cost_max+1; i++) {
        dp_a[0][i] = 0;
        dp_b[0][i] = 0;
    }
    for (int i = 0; i < N+1; i++) {
        dp_a[i][0] = 0;
        dp_b[i][0] = 0;
    }

    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < cost_max+1; j++) {
            if (j >= C[i-1]) {
                if (dp_a[i-1][j-C[i-1]]+A[i-1] >= dp_a[i-1][j]) {
                    dp_a[i][j] = dp_a[i-1][j-C[i-1]]+A[i-1];
                    dp_b[i][j] = dp_b[i-1][j-C[i-1]]+B[i-1];
                } 
                else {
                    dp_a[i][j] = dp_a[i-1][j];
                    dp_b[i][j] = dp_b[i-1][j];
                }
            }
            else {
                dp_a[i][j] = dp_a[i-1][j];
                dp_b[i][j] = dp_b[i-1][j];
            }
        }
    }

    for (int i = 1; i < cost_max+1; i++) {
        for (int j = 1; j < N+1; j++) {
            if (dp_a[i][j]*Mb == dp_b[i][j]*Ma) {
                cout << j << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;

    // for (int i = 0; i < N+1; ++i) {
    //     for (int j = 0; j < cost_max+1; j++) {
    //         if (j) cout << " ";
    //         cout << dp_a[i][j];
    //     }
    //     cout << endl;
    // }
}