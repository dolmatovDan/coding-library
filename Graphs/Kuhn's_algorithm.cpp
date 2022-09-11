#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> p, used;
int n;

bool dfs(int v) {
    if (used[v])
        return false;
    used[v] = 1;
    for (int u : g[v]) {
        if (p[u] == -1 || dfs(p[u])) {
            p[u] = v;
            return true;
        }
    }
    return false;  
}

int knuth() {
    memset(p, -1, sizeof p);
    int cnt = 0;
    for (int v = 0; v < n; ++v) {
        memset(used, 0, sizeof used);
        if (dfs(v)) {
            cnt++;
        }
    }
    return cnt;
}

signed main() {
    return 0;
}