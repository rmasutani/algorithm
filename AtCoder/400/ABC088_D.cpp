#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int MAX = 51;
char grid[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int H, W;
int min_count = 100000000;

void dfs_count(int h, int w, int count)
{
    visited[h][w] = true;

    for (int i = 0; i < 4; i++)
    {
        int nh = h + dx[i];
        int nw = w + dy[i];

        if (nh < 0 || nh > H - 1 || nw < 0 || nw > W - 1)
        {
            continue;
        }
        if (visited[nh][nw])
        {
            continue;
        }
        if (grid[nh][nw] == '#')
        {
            continue;
        }

        if (nh == H - 1 && nw == W - 1)
        {
            cout << "Reached goal: " << count << endl;
            min_count = min(min_count, count + 1);
            continue;
        }

        dfs_count(nh, nw, count + 1);
    }
}

int main()
{
    int black_count = 0;
    cin >> H >> W;
    // cout << H << W << endl;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            std::cin >> grid[h][w];
            visited[h][w] = false;

            if (grid[h][w] == '#')
                black_count++;
        }
    }

    dfs_count(0, 0, 1);

    if (min_count == 100000000)
        cout << -1 << endl;
    else
        cout << H * W - (black_count + min_count) << endl;
    cout << min_count << endl;

    return 0;
}