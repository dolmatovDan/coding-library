#include <bits/stdc++.h>
//Одновление на полуинтервале, сохраняем инвариант: старые операции хранятся снизу
using namespace std;
#define len(a) (int)(a.size())
typedef long long ll;
typedef vector<int> vi;
#define fo(i, n) for(int i = 0; i < n; ++i)
#define int long long
int n;
vi t;
vi a;
const ll NO_OPER = -1e9;

void push(int v, int tl, int tr) {
    if (t[v] == NO_OPER or tl + 1 == tr) return;
    t[2 * v + 1] = t[v];
    t[2 * v + 2] = t[v];
    t[v] = NO_OPER;
}

void modify(int l, int r, ll x, int v = 0, int tl = 0, int tr = n) {
    push(v, tl, tr);
    if (l >= tr or r <= tl)
        return;
    if (l <= tl and r >= tr) {
        t[v] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    modify(l, r, x, v * 2 + 1, tl, tm);
    modify(l, r, x, v * 2 + 2, tm, tr);
}

ll get(int pos, int v = 0, int tl = 0, int tr = n) {
    push(v, tl, tr);
    if (tl + 1 == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos < tm) {
        return get(pos, 2 * v + 1, tl, tm);
    } else {
        return get(pos, 2 * v + 2, tm, tr);
    }
}

void solve() {
    int m;
    cin >> n >> m;
    t.resize(4 * n);
    fo(i, m) {
        string com;
        cin >> com;
        if (com == "1") {
            int l, r,v;
            cin >> l >> r >> v;
            modify(l, r, v);
        } else {
            int x;
            cin >> x;
            cout << get(x) << endl;
        }
    }
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