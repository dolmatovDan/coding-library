#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const int MAX = 1000000000000 * 2;

int dejkstra(vector<vector<pii>> g, int start, int finish) {
    int n = sz(g);
    set<pii> s;
    s.insert(MP(0, start));
    vector<int> d(n, MAX);
    d[start] = 0;
    while (not s.empty()) {
        int mn = (*s.begin()).S;
        s.erase(*s.begin());
        for(pii e: g[mn]) {
            if (d[e.F] > d[mn] + e.S) {
                s.erase(MP(d[e.F], e.F));
                d[e.F] = d[mn] + e.S;
                s.insert(MP(d[e.F], e.F));
            }
        }
    }
    if (d[finish] == MAX) return -1;
    else return d[finish];
}

int solve() {
    int n, start, finish;
    cin >> n >> start >> finish;
    start--, finish--;
    vector<vector<pii>> g(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x != -1 and x != 0) {
                g[i].push_back(MP(j, x));
            }
        }
    }
    cout << dejkstra(g, start, finish) << endl;
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


