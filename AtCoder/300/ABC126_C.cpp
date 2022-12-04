#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    double answer = 0;

    for (int i = 1; i < N + 1; i++)
    {
        if (i >= K)
        {
            answer += (double)1 / N;
        }
        else
        {
            int count = ceil(log2((double)K / i));
            answer += ((double)1 / N) * pow(((double)1 / 2), count);
        }
    }
    cout.precision(13);
    cout << answer << endl;
    return 0;
}