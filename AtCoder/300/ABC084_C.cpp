#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int NMAX = 510;

int main(void)
{
    int N;
    cin >> N;
    int C[NMAX], S[NMAX], F[NMAX];
    for (int i = 0; i < N - 1; i++)
    {
        cin >> C[i] >> S[i] >> F[i];
    }

    // 現在時刻を記録
    int cur = 0;

    for (int i = 0; i < N - 1; i++)
    {
        // iがスタート地点
        cur = 0;
        for (int j = i; j < N - 1; j++)
        {
            if (S[j] >= cur)
            {
                cur = S[j] + C[j];
            }
            else
            {
                double k;
                k = std::ceil((double)(cur - S[j]) / F[j]);
                cur = S[j] + (int)k * F[j] + C[j];
            }
        }

        cout << cur << endl;
    }
    cout << 0 << endl;

    return 0;
}