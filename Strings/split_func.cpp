#include <bits/stdc++.h>
using namespace std;
#define fo3(i, s, n) for(int i = s; i < n; i++)
#define fo2(i, a) for(auto i: a)
#define len(a) (int)(a.size())
#define vec vector
#define pb push_back
#define deb(x) cout << (#x) << ' ' << '=' << ' ' << (x) << endl
typedef vector<int> vi;


vec<string> split(string s, string sep=" ") {
    vec<string> res;
    string term = "#";
    s = sep + term + s;
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
    string cur = "";
    fo3(i, len(term) + len(sep), len(s)) {
        if ((z[i] == len(sep) and len(cur))) {
            res.pb(cur);
            cur = "";
        } else if(z[i] != len(sep)) {
            cur += s[i];
        }
        if (z[i] != len(sep) and i == len(s) - 1) {
            res.pb(cur);
        }
        if (z[i] == len(sep)) i += z[i] - 1;
    }
    return res;
}

signed main()
{
    string s, sep;
    getline(cin, s);
    cin >> sep;
    vec<string> res;
    if (sep != "#") res = split(s, sep);
    else res = split(s);
    fo2(i, res) cout << i << ' ';
}