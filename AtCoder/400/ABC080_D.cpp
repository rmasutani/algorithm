#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 100010;

int s[NMAX];
int t[NMAX];
int c[NMAX];

vector<pair<int, int>> cs;

int main() {
    int N, C;
    cs.assign(N, make_pair(-1, -1));
    for (int i = 0; i < N; i++) cin >> s[i] >> t[i] >> c[i];

    for (int i = 0; i < N; i++) {
        if (cs[i].first < 0) {
            cs[i].first = s[i];
            cs[i].second = t[i];
        } else {
            cs[i].first = min(cs[i].first, s[i]);
            cs[i].second = min(cs[i].second, t[i]);
        }
    } 

    int ans = 0;
    vector<pair<int, int>> machines;
    for (int i = 0; i < cs.size(); i++) {
        if (cs[i].first < 0) continue;

        bool found = false;
        for (int j = 0; machines.size(); j++) {
            // no overlap and later
            if (cs[i].first - 0.5 >= machines[j].second) {
                
            } else if (cs[i].second < machines[i].first - 0.5) 
        }
    }   
    return 0;
}