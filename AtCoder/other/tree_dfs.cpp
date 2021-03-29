#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge {
    int to, id;
};

vector<vector<Edge>> to;
vector<int> ans;


void dfs(int v, int p=-1) {
    rep(i, sz(to[v])) {
        int u = to[v][i];
        if (u == p) continue;
        dfs(u, v);
    }
}

int main() {
    int n;
    cin >> n;
    to.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        to[a].push_back((Edge){b, i});
        to[b].push_back((Edge){a, i});
    }
    dfs(0);
    return 0;
}