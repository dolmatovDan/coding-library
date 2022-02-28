#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fo2(i, a) for(auto i: a)
#define fo3(i, s, n) for(int i = s; i < n; i++)
#define len(a) (int)(a.size())

typedef vector<int>     vi;

void solve() {
    string s;
    cin >> s;
    int n = len(s);
    vi z(n);
    z[0] = 0;
    int l = 0, r = 0;
    fo3(i, 1, n) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    fo(i, n) cout << z[i] << ' ';
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
