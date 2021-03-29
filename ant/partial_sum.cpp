#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int KMAX = 1000000;

int dp[KMAX+1];

int main() {
    int n = 3;
    int a[] = {3, 5, 8};
    int m[] = {3, 2, 2};
    int K = 17;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    

    
    return 0;
}