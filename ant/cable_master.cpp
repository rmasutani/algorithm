#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 10001;

int L[NMAX];

int main(void) {
    int N, K;
    cin >> N >> K;
    int left = 0;
    int right;
    int l_sum = 0;
    for (int i = 0; i < N; i++){
        double l; int l2;
        cin >> l;
        l2 = l * 1000;
        L[i] = l2;

        l_sum += L[i];
    }

    right = l_sum / K + 1;

    // cout << "left " << left << endl;
    // cout << "right " << right << endl;

    
    while (right - left > 1) {
        int mid = (right + left) / 2;
        
        int cur_k = 0;
        for (int i = 0; i < N; i++) {
            cur_k += (int)(L[i] / mid);
        }

        cout << cur_k << endl;
        
        if (cur_k < K) right = mid;
        else left = mid;

    }

    cout << right << endl;
    
    
    return 0;
}
