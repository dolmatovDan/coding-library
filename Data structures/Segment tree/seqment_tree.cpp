#include <bits/stdc++.h>
//Дерево на полуинтервалах 
using namespace std;
#define len(a) (int)(a.size())
typedef vector<int> vi;

int n;
vi t;
vi a;

void build(int l, int r, int v) {
    if (l + 1 == r) {
        t[v] = a[l];
    } else {
        int tm = (l + r) / 2;
        build(l, tm, 2 * v + 1);
        build(tm, r, 2 * v + 2);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
}

int sum(int l, int r, int v = 0, int tl = 0, int tr = n) {
    if (tl >= l && tr <= r) {
        return t[v];
    }
    if (tr <= l || r <= tl) {
        return 0;
    }
    int mid = (tr + tl) / 2; // mid = l + (r - l) / 2;
    return sum(l, r, 2 * v + 1, tl, mid) + sum(l, r, 2 * v + 2, mid, tr);
}

void update (int pos, int new_val, int v = 0, int tl = 0, int tr = n) {
	if (tl + 1 == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos < tm) update (pos, new_val, v * 2 + 1, tl, tm);
		else update (pos, new_val, v * 2 + 2, tm, tr);
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

int solve() {
    cin >> n;
    t.resize(4 * n + 1);
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
