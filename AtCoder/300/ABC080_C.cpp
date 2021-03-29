#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 100;
const int DAY = 5;
const int TIME = 2;
int F[NMAX][DAY*TIME], P[NMAX][DAY*TIME+1];

int getCost(int a[], int b[], int N) {
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cout << a[i] << " " << b[i] << endl; 
        cost += (a[i] * b[i]);
    }
    return cost;
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < DAY*TIME; j++) {
                cin >> F[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < DAY*TIME; j++) {
            cin >> P[i][j]; 
        }
    }

    int min_cost = 0;
    int max_cost = 0;
    for (int i = 0; i < N; i++) {
        int cur_cost = getCost(F[i], P[i], DAY*TIME);
        min_cost = max(min_cost, cur_cost);
        if (cur_cost >= 0) max_cost += cur_cost;
    }

    if (max_cost >= 0) cout << max_cost << endl;
    else cout << min_cost << endl;

    return 0;
}
