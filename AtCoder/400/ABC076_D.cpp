#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <cstdint>
#include <string>
#include <sstream>
using namespace std;
const int NMAX = 105;
const int INF=1001001001;
double ts[NMAX];
double vs[NMAX];

template<class T> bool chmin(T&a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> ts[i]; 
    for (int i = 0; i < N; i++) cin >> vs[i];

    int sum_t = 0;
    for (int i = 0; i < N; i++) sum_t += ts[i];
    vector<double> maxv(2 * sum_t + 1, INF);

    // fill maxv
    int prev_pos = 0;
    for (int i = 0; i < N; i++) {
        for (int j = prev_pos; j <= prev_pos + ts[i]*2; j++) {
            chmin(maxv[j], vs[i]);
        }
        prev_pos += ts[i] * 2;
    }
    maxv[0] = 0;
    maxv[2*sum_t] = 0;

    for (int i = 1; i <= 2*sum_t; i++) {
        maxv[i] = min(maxv[i-1]+0.5, maxv[i]);
    } 

    for (int i = 2*sum_t-1; i >= 0; i--) {
        maxv[i] = min(maxv[i+1]+0.5, maxv[i]);
    }

    // calculation
    double ans = 0;
    for (int i = 0; i < 2*sum_t; i++) {
        ans += (maxv[i] + maxv[i+1])/4;
    }

    // for (int i = 0; i < 2*sum_t+1; i++) {
    //     cout << maxv[i] << endl;
    // }

    printf("%.10f\n",ans);
    return 0;
}