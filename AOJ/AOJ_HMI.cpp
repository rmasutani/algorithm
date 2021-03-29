#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
static const int N = 50;

int W, H;
bool visited[N][N];
int map[N][N];

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void dfs(int h, int w) {
    visited[h][w] = true;

    for (int i = 0; i < 8; ++i) {
        int nh = h + dx[i];
        int nw = w + dy[i];

        if (nh < 0 || nh > H-1 || nw < 0 || nw >W-1) continue;
        if (visited[nh][nw]) continue;
        if (map[nh][nw] == 0) continue;

        dfs(nh, nw);
    }
}

int main() {
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;

        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                cin >> map[h][w];
            }
        }

        memset(visited, 0, sizeof(visited));

        int count = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (visited[h][w] || map[h][w] == 0) continue;
                dfs(h, w);
                ++count;
            }
        }

        cout << count << endl;
    }


    return 0;
}