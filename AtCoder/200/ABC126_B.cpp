#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    int first = stoi(S.substr(0, 2));
    int second = stoi(S.substr(2, 2));

    // YY&MM
    if (first > 0 && first <= 12)
    {
        if (second > 0 && second <= 12)
        {
            cout << "AMBIGUOUS" << endl;
        }
        else
        {
            cout << "MMYY" << endl;
        }
    }
    else
    { // YY
        if (second > 0 && second <= 12)
        {
            cout << "YYMM" << endl;
        }
        else
        {
            cout << "NA" << endl;
        }
    }

    return 0;
}