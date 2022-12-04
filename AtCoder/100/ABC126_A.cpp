#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    for (int i = 0; i < N; i++)
    {
        if (i == K - 1)
        {

            cout << (char)tolower(S.at(i));
            continue;
        }
        cout << S.at(i);
    }

    cout << endl;

    return 0;
}