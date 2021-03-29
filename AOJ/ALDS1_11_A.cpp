#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int adj_mat[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_mat[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int m, l; cin >> m >> l;
        for (int j = 0; j < l; j++) {
            int k; cin >> k;
            adj_mat[i][k-1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) cout << " ";
            cout << adj_mat[i][j];
        }
        cout << endl;
    }

    return 0;
}