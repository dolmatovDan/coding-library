#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll MAX = LLONG_MAX;

vector<vector<pii>> g;
vector<bool> vis;
vector<int> first;
vector<pii> path;

void euler(int v) {
    while(first[v] < sz(g[v])) {
        pii p = g[v][first[v]];
        first[v]++;
        int i = p.F;
        int u = p.S;
        if (not vis[i]) {
            vis[i] = true;
            euler(u);
            path.push_back(MP(u, v));
        }
    }
}



int solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(m + 2, false);
    first.resize(n + 1);
    int x = -1, y = -1;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(MP(i, v));
        g[v].push_back(MP(i, u));
    }
    for(int i = 0; i < n; i++) {
        if (sz(g[i]) % 2 == 1) {
            if (x == -1) {
                x = i;
                cout << x << endl;
            } else {
                y = i;
                cout << y << endl;

            }
        }
    }
    int k = n;
    g[k].push_back(MP(m, x));
    g[x].push_back(MP(m, k));

    g[k].push_back(MP(m + 1, y));
    g[y].push_back(MP(m + 1, k));
    euler(k);
    cout << "----------" << endl;

    for(int i = 1; i < sz(path) - 1; i++) cout << path[i].F + 1<< ' ' << path[i].S + 1 << endl;

    return 0;
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
/*
5 6
1 2
2 5
1 5
3 5
3 4
4 5
*/
/*
6 6
1 2
2 3
3 4
3 5
3 6
5 6
*/
