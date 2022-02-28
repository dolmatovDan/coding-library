#include <bits/stdc++.h>

using namespace std;
#define len(a) (int)(a.size())
typedef vector<int> vi;

vi t;

void build(vi &a, int tl, int tr, int v) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, tl, tm, 2 * v + 1);
        build(a, tm + 1, tr, 2 * v + 2);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
}

int sum(int v, int tl, int tr, int left, int right) {
    if (left > right or tl > right or tr < left) return 0;
    if (tl == left and tr == right) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2 + 1, tl, tm, left, min(tm, right)) + sum(v * 2 + 2, tm + 1, tr, max(tm + 1, left), right);
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) update (v * 2 + 1, tl, tm, pos, new_val);
		else update (v * 2 + 2, tm + 1, tr, pos, new_val);
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

int solve() {
    int n;
    cin >> n;
    t.resize(4 * n + 1);
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    build(a, 0, n - 1, 0);
    for(int i = 0; i < len(t); i++) cout << t[i] << ' ';
    cout << '\n';
    cout << sum(0, 0, n - 1, 1, 2) << endl;
    update(0, 0, n - 1, 2, 15);

    cout << sum(0, 0, n - 1, 1, 2) << endl;
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
5
6 8 9 3 2
*/
