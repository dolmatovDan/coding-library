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

vector<pii> path;
vector<vector<pii>> g;
vector<int> first;
vector<bool> vis;

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
    cin >> n>> m;
    g.resize(n);
    first.resize(n);
    vis.resize(m, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(MP(i, v));
        g[v].push_back(MP(i, u));
    }
    euler(0);
    cout << "-------" << endl;
    for(int i = 0; i < sz(path); i++) cout << path[i].F + 1 << ' ' << path[i].S + 1<< endl;


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
6 7
1 2
2 3
2 4
3 4
3 5
4 5
5 6
*/
