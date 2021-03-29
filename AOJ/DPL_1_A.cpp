#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int c[M];

    for (int i = 0; i < M; ++i) cin >> c[i];

    // initialize Dp table
    int T[M][N+1];
    for (int i = 0; i < M; ++i) T[i][0] = 0;
    for (int j = 1; j < N+1; ++j) T[0][j] = j / c[0];
    
    for (int i = 1; i < M; ++i) {
        for (int j = 1; j < N+1; ++j) {
            if (j < c[i]) {
                T[i][j] = T[i-1][j];
                continue;
            }

            T[i][j] = min(T[i-1][j], T[i][j-c[i]]+1);
        }
    }
  
    cout << T[M-1][N] << endl;
  
    return 0;
}


