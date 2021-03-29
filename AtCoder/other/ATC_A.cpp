#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
using Field = vector<vector<string>>;

bool visited[500][500];
int H, W;
vector<string> field;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void dfs(int h, int w) {
    visited[h][w] = true;

    for (int i = 0; i < 4; i++) {
        int nh = h + dx[i];
        int nw = w + dy[i];

        if (nh < 0 || nh > H-1 || nw < 0 || nw > W-1) continue;
        if (field[nh][nw] == '#') continue;

        if (visited[nh][nw]) continue;

        dfs(nh, nw);
    }
}

int main() {
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; h++) cin >> field[h];

    int sh, sw, gh, gw;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (field[h][w] == 's') sh = h, sw = w;
            if (field[h][w] == 'g') gh = h, gw = w;
        }

    }

    memset(visited, 0, sizeof(visited));
    dfs(sh, sw);

    if (visited[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}