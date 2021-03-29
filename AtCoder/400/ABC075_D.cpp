#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> x(N), y(N);
    vector<int> xary, yary;

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(begin(xary), end(xary));
    sort(begin(yary), end(yary));

    ll ans = 1LL * (xary[N-1] - xary[0]) * (yary[N-1] - yary[0]);

    // 2次元累積和
    for (int xi = 0; xi < N; ++xi) {
        for (int xj = xi+1; xj < N; ++xj) {
            for (int yi = 0; yi < N; ++yi) {
                for (int yj = yi+1; yj < N; ++yj) {
                    int num = 0;

                    ll lx = xary[xi], rx = xary[xj];
                    ll by = yary[yi], uy = yary[yj];

                    for (int i = 0; i < N; ++i) {
                        if (lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy) {
                            num++;
                        }
                    }

                    if (num >= K) ans = min(ans, 1LL * (rx - lx) * (uy - by));
                }
            }
        } 
    }

    cout << ans << endl;

    return 0;
}