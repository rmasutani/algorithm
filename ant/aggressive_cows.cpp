#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 100010;

int N, M;
int x[NMAX];

bool C(int d) {
    int last = 0;
    for (int i = 1; i < M; i++) {
        int crt = last + 1;
        
        while (crt < N && x[crt] - x[last] < d) {
            crt++;
        }

        if (crt == N) return false;
        last = crt;
    }

    return true;
}

int main(void) {

    return 0;
}