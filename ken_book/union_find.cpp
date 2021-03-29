#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    // par: 親頂点の番号. 自身が根の時は-1
    // siz: 各頂点の属する熱木々の頂点数
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) { }

    // 根を求める
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか
    bool issame(int x, int y) {
        return root(x)== root(y);
    }

    // xとyのグループを合併
    // r_y が r_x の子になるようにする
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    //グラフの連結成分の個数を求めてみる
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);

    //各辺に対する処理
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    // 集計（「根付き木の根となっている頂点」の個数を数える）
    int res = 0;
    for (int x = 0; x < N; x++) {
        if (uf.root(x) == x) res++;
    }

    cout << res << endl;
}
