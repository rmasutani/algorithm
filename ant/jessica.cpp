#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> A;
vector<int> cum_sum;

int main() {
    int P;
    cin >> P;
    A.resize(P);
    cum_sum.resize(P+1);
    for (int i = 0; i < P; i++) cin >> A[i];

    set<int> s(A.begin(), A.end());
    int sum = 0;
    for (auto it: s) {
        sum += it;
    }

    //
    //
    for (int i = 0; i < P; i++) {
        cum_sum[i+1] = cum_sum[i] + A[i];
    }

    if (cum_sum[P] < sum) {
        cout << "0" << endl;
    }

    int res = P;
    for (int s = 0; cum_sum[s] + sum <= cum_sum[P]; s++) {
        int t = lower_bound(cum_sum.begin()+s, cum_sum.end()+P, cum_sum[s] + sum) - cum_sum.begin();
        res = min(res, t-s);
    }

    cout << res << endl;

    return 0;
}