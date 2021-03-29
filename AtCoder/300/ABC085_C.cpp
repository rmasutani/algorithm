#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int COEF_X = 9000;
const int COEF_Y = 5000;

int main() {
    int N, Y;
    cin >> N >> Y;

    int A = 10000 * N - Y;
    int x = -1;
    int y = 0;

    while (A >= 0) {
        if (A % COEF_X == 0) {
            x = A / COEF_X;
            break;
        }
        A -= COEF_Y;
        y++;
    }

    if (x == -1 || x + y > N) {
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
    else {
        cout << N - x - y << " " << y << " " << x << endl;
    }


    return 0;
}