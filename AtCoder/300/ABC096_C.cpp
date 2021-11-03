#include <iostream>
#include <vector>
#include <algorithm>
const int MAX = 51;
char grid[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int H, W;
int count;

void dfs_count(int h, int w)
{
    visited[h][w] = true;

    for (int i = 0; i < 4; i++)
    {
        int nh = h + dx[i];
        int nw = w + dy[i];

        if (nh < 0 || nh > H - 1 || nw < 0 || nw > W - 1)
            continue;
        if (visited[nh][nw])
            continue;
        if (grid[nh][nw] == '.')
            continue;

        count += 1;
        dfs_count(nh, nw);
    }
}

int main(void)
{
    std::cin >> H >> W;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            std::cin >> grid[h][w];
            visited[h][w] = false;
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            count = -1;

            if (!visited[h][w] && grid[h][w] == '#')
            {
                // std::cout << grid[h][w] << std::endl;
                count = 1;
                dfs_count(h, w);
            }

            // std::cout << count << std::endl;

            if (count == 1)
            {
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "Yes" << std::endl;

    return 0;
}