#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fo(i, n) for(int i = 0; i < n; i++)
vi t;
int n;

void push(int v) {
    if (t[v] != -1) {
        t[v * 2 + 1] = t[v * 2 + 2] = t[v];
        t[v] = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int c) {
    if (l > r) return;
    if (l == tl and r == tr) t[v] = c;
    else {
        push(v);
        int tm = (tl + tr) / 2;
        update (v * 2 + 1, tl, tm, l, min(r, tm), c);
		update (v * 2 + 2, tm + 1, tr, max(l, tm + 1), r, c);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return get(v * 2 + 1, tl, tm, pos);
    else return get(v * 2 + 2, tm + 1, tr, pos);
}

signed main()
{
    int n;
    cin >> n;
    t.resize(4 * n);
    fo(i, n) update(0, 0, n - 1, i, i, i);
    update(0, 0, n - 1, 0, 2, 5);
    fo(i, n) cout << get(0, 0, n - 1, i) << ' ';
    return 0;
}