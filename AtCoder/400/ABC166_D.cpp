#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using ll = long long;

int main() {
    int X;
    std::cin >> X;

    for (int i = -120; i <= 119; i++) {
        int cand = i*i*i*i*i - X;
        for (int j = -119; j <= 118; j++) {
            if (j*j*j*j*j == cand) {
                std::cout << i << " " << j << std::endl;
                return 0;
            }
        }
    }
    return 0;
}