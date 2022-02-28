#include <bits/stdc++.h>
using namespace std;

#define len(a) (int)(a.size())
#define fo3(i, s, n) for(int i = s; i < n; i++)
#define fo(i, n) for(int i = 0; i < n; i++)
#define fo2(i, a) for(auto i: a)
#define deb(a) cout << (#a) << " = " << a << endl
typedef vector<int> vi;

vector<int> t;
int n;

void inc (int i, int d) {
	for (; i < n; i = (i | (i+1))) t[i] += d;
}

int sum (int l, int r) {
    l--;
    int res = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		res += t[r];
	for (; l >= 0; l = (l & (l+1)) - 1)
		res -= t[l];
	return res;
}

void init (vector<int> a) {
    t[0] = a[0];
    for (int i = 1; i < len(a); i++) t[i] = t[i - 1] + a[i];
    for (int i = len(a) - 1; i > 0; i--) {
        int lower_i = (i & (i+1)) - 1;
        if (lower_i >= 0) t[i] -= t[lower_i];
    }
}

void solve() {
    int q;
    cin >> n >> q;
    vi a(n);
    t.resize(n);
    fo(i, n) cin >> a[i];
    init(a);
    fo(i, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << sum(l, r) << endl;
    }
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