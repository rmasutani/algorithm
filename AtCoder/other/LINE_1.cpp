#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include "dice.h"
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const int NMAX = 100;
const int MMAX = 100;


// 移動パターン
int N, M, Q;
int dh[] = {1, 0};
int dw[] = {0, 1};
char direc[] = {'S', 'E'};


// クエリ含む盤面
vector<vector<int>> board;

int dp[NMAX][MMAX];
int rec(int h, int w, dice d, int dist) {
    if (h == N-1 && w == M-1) return dist;
    if (dp[h][w] != INF) return dp[h][w];

    int res = INF;
    // 全ての移動パターン
    for (int i = 0; i < 2; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nh > N-1 || nw < 0 || nw >M-1) continue;

        // 新しいdiceオブジェクトの作成
        int next_pat[6];
        for (int i = 0; i < 6; i++) {
          next_pat[i] = d[i];
        }
        // 次の方向にロールする
        dice next_d(next_pat);
        next_d.mov(direc[i]);

        if (next_d[0] != board[nh][nw]) chmin(res, rec(nh, nw, next_d, dist+1));
    }

    return dp[h][w] = res;
}


int main(int argc, char *argv[]) {
  cin >> N >> M >> Q;
  // 盤面入力
  board.assign(N, vector<int>(M, -1));
  for (int i = 0; i < Q; i++) {
    int s, t, x;
    cin >> s >> t >> x;
    board[s][t] = x;
  }

  //memo initialize
  for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++) {
          dp[i][j] = INF;
      }
  }

  int pattern[] = {1, 2, 4, 3, 5, 6};
  dice d(pattern);

  int res = INF;
  chmin(res, rec(0, 0, d, 0));

  if (res != INF) {
    cout << "YES" << endl;
    cout << res << endl;
  } else {
    cout << "NO" << endl;
  }


  return 0;
}
