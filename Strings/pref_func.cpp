#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i = 0; i < n; i++)
#define fo2(i, a) for(auto i: a)
#define fo3(i, s, n) for(int i = s; i < n; i++)
#define len(a) (int)(a.size())

typedef vector<int> vi;
vi pref_func(string s) {
    int n = len(s);
    vi p(n);
    fo3(i, 1, n) {
        int j = p[i - 1];
        while(j > 0 and s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

void solve() {
    string s;
    cin >> s;
    vi a = pref_func(s);
    fo2(i, a) cout << i << ' ';

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