#include <bits/stdc++.h>
//Одновление на полуинтервале
using namespace std;
#define len(a) (int)(a.size())
typedef vector<int> vi;
int n;
vi t;
vi a;

void add(int l, int r, int x, int v = 0, int tl = 0, int tr = n) {
    if (l >= tr or r <= tl)
        return;
    if (l <= tl and r >= tr) {
        t[v] += x;
        return;
    }
    int tm = (tl + tr) / 2;
    add(l, r, x, v * 2 + 1, tl, tm);
    add(l, r, x, v * 2 + 2, tm, tr);
}

int get(int pos, int v = 0, int tl = 0, int tr = n) {
    if (tl + 1 == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos < tm) {
        return get(pos, v * 2 + 1, tl, tm) + t[v];
    } else {
        return get(pos, v * 2 + 2, tm, tr) + t[v];
    }
}

void solve() {
    return;
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