#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool search(int sum, string out, string rest)
{
    // cout << out << ", " << rest << ", " << sum << endl;
    if (!rest.length())
    {
        if (sum == 7)
        {
            cout << out << "=7" << endl;
            return true;
        }

        return false;
    }

    int head = int(rest[0] - '0');
    // cout << "Head value: " << head << endl;
    if (search(sum + head, out + "+" + rest.substr(0, 1), rest.substr(1)))
        return true;
    else
        return search(sum - head, out + "-" + rest.substr(0, 1), rest.substr(1));
}

int main(void)
{
    string s;
    cin >> s;
    search(int(s[0] - '0'), s.substr(0, 1), s.substr(1));
    return 0;
}