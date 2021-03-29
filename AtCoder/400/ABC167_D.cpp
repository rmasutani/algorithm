#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;

std::vector<int> A;
std::vector<int> visited;


int main(void) {
    int N;
    ll K;
    std::cin >> N >> K;
    A.resize(N);
    visited.assign(N, -1);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A[i] = --a;
    }

    // サイクルを求める
    int cycle_len = N;
    int to_cycle = 0;
    visited[0] = 0;

    int cur_v = A[0];
    for (int i = 1; i < N; i++) {
        if (visited[cur_v] != -1) {
            cycle_len = i - visited[cur_v];
            to_cycle = visited[cur_v];
            break;
        }
        visited[cur_v] = i;
        cur_v = A[cur_v];
    }


    int new_n;
    if (K < to_cycle) new_n = K;
    else new_n = to_cycle + (K - to_cycle) % cycle_len;

    cur_v = A[0];
    for (int i = 1; i < new_n; i++) cur_v = A[cur_v];

    std::cout << cur_v+1 << std::endl;

    return 0;
}