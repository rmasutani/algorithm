#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
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
    int N, W;
    cin >> N >> W;
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++) cin >> value[i] >> weight[i];

    //dp table definition
    vector<vector<int> > dp(N+1, vector<int>(W+1, 0));

    // けんちょんバージョン
    // for (int i = 0; i < N; i++) {
    //     for (int w = 0; w < W+1; w++) { 
    //         if (w - weight[i] >= 0) {
    //             chmax(dp[i+1][w], dp[i][w-weight[i]] + value[i]);
    //         }
    //         chmax(dp[i+1][w], dp[i][w]);
    //     }
    // }

    // my version もらうDP
    for (int i = 1; i < N+1; i++) {
        for (int w = 1; w < W+1; w++) {
            if (w - weight[i-1] >= 0) {
                chmax(dp[i][w], dp[i-1][w-weight[i-1]]+value[i-1]);
            }
            chmax(dp[i][w], dp[i-1][w]);
        }
    }


    // printTable(dp);
    cout << dp[N][W] << endl;
    return 0;
}