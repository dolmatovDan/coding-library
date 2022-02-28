#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back
#define fo(i, n) for(int i = 0; i < n; i++)
#define fo2(i, a) for(auto i: a)
#define fo3(i, s, n) for(int i = s; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi colors;
vi res;
vi used;

void dfs(int v) {
    if (colors[v] == 0) colors[v] = 1;
    if (colors[v] == 2) return;
    fo2(u, g[v]) {
        if (colors[u] == 0) {
            dfs(u);
        }
    }
    colors[v] = 2;
    res.pb(v);
}

bool dfs2(int v) {
    used[v] = 1;
    fo2(u, g[v]) {
        if (used[u] == 1) {
            return true;
        }
        if (used[u] == 0) {
            if (dfs2(u)) {
                return true;
            }
        }
    }
    used[v] = 2;
    return false;
}

int solve() {
    int n, m;
    cin >> n >> m;
    colors.resize(n + 1);
    g.resize(n + 1);
    used.resize(n + 1);
    fo3(i, 1, n + 1) {
        g[0].pb(i);
    }
    fo(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    fo(i, n + 1) { //���������, ��� ��� ������
        if(dfs2(i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    dfs(0);
    reverse(all(res));
    fo3(i, 1, n + 1) {
        cout << res[i] << ' ';
    }

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


