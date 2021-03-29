#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int WMAX = 10000;
const int NMAX = 1000;

int dp[NMAX+1][WMAX+1];
struct Item {
    int v;
    int w;
    Item(int v, int w) : v(v), w(w) {}

    bool operator < (const Item& item) const
    {
        return w < item.w;
    }
};

vector<Item> item;

int main()
{
    int N, W;
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int v, w;
        cin >> v >> w;
        item.push_back(Item(v, w));
    }

    // DP table initialization
    for (int i = 0; i < N; i++) dp[i][0] = 0;
    for (int i = 0; i < W; i++) dp[0][i] = 0;

    for (int i = 1; i < N+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            if (j - item[i-1].w >= 0) 
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-item[i-1].w] + item[i-1].v);
                dp[i][j] = max(dp[i][j], dp[i-1][j-item[i-1].w] + item[i-1].v);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][W] << endl;
    
    return 0;
}