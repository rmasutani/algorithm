#include <iostream>
#include <vector>
using namespace std;
const int INF = 100000;

template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

void printTable(const vector<vector<int> > &table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            if (!j) cout << table[i][j];
            else cout << " " << table[i][j];
        }
        cout <<endl;
    }
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> C(N);
    for (int i = 0; i < M; i++) cin >> C[i]; 

    vector<vector<int> > dp(M+1, vector<int>(N+1, INF));

    // index に注意
    for (int i = 0; i < M+1; i++) {
        for (int c = 0; c < N+1; c++) {
            if (c == 0) {
                dp[i][c] = 0;
                continue;
            }
            if (c - C[i-1] >= 0) {
                chmin(dp[i][c], dp[i][c - C[i-1]]+1);
            }
            chmin(dp[i][c], dp[i-1][c]);
        }
    }
    cout << dp[M][N] << endl;
    // printTable(dp);
    return 0;
}