#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    stack<char> st;
    char s[20];
    cin >> s;

    int i = 0;
    while (s[i])
    {
        // cout << i << "th letter" << endl;
        if (s[i] == '0' || s[i] == '1')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
                st.pop();
        }

        i++;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}