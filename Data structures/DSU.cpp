#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i = 0; i < n; i ++)
typedef vector<int> vi;
vi p, r; // p - предки, r - ранги

int get(int a) {
    return p[a] = (a == p[a] ? a : get(p[a]));
}

void union_d(int _a, int _b) {
    int a = get(_a);
    int b = get(_b);
    if (r[a] == r[b]) r[a]++;
    if (r[a] > r[b]) {
        p[b] = a;
    } else {
        p[a] = b;
    }
    p[a] = b;
}
    

void solve() {
    int n;
    cin >> n;
    p.resize(n);
    r.resize(n, 0);
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}