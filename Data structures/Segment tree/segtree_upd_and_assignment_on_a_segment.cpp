#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll infll = 2e18;

struct segtree {
    struct node {
        ll set, min;
    };
    vector<node> tree;
    int size;
    ll NO_OP = -infll;
    ll NEUTRAL = infll;
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2 * size, {0, 0});
    }
    ll op_modify(ll a, ll b, int len) {
        if (b == NO_OP) return a;
        return b;
    }
    ll op_sum(ll a, ll b) {
        return min(a, b);
    }
    void propagate(int x, int lx, int rx) {
        if (tree[x].set == NO_OP or rx - lx == 1) return;
        int m = (lx + rx) / 2;
        tree[x * 2 + 1].set = op_modify(tree[x * 2 + 1].set, tree[x].set, m - lx);
        tree[x * 2 + 1].min = op_modify(tree[2 * x + 1].min, tree[x * 2 + 1].set, m - lx);

        tree[x * 2 + 2].set = op_modify(tree[x * 2 + 2].set, tree[x].set, rx - m);
        tree[x * 2 + 2].min = op_modify(tree[2 * x + 2].min, tree[x * 2 + 1].set, rx - m);
        tree[x].set = NO_OP;
    }

    void mult(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        if (l >= rx or lx >= r) return;
        if (lx >= l and rx <= r) {
            tree[x].set = op_modify(tree[x].set, v, m - lx);
            tree[x].min = op_modify(tree[x].min, tree[x].set, m - lx);
            return;
        }
        mult(l, r, v, x * 2 + 1, lx, m);
        mult(l, r, v, x * 2 + 2, m, rx);
        tree[x].min = op_sum(tree[x * 2 + 1].min, tree[x * 2 + 2].min);
    }

    void mult(int l, int r, int v) {
        mult(l, r, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx) return NEUTRAL;
        if (lx >= l && rx <= r) {
            return tree[x].min;
        }
        int m = (lx + rx) / 2;
        ll m1 = sum(l, r, x * 2 + 1, lx, m);
        ll m2 = sum(l, r, x * 2 + 2, m, rx);
        return op_sum(m1, m2);
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
    void print() {
        for(auto x:tree) cout << x.min << ' ' << x.set << '\n';
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    int com;
    while (m--) {
        cin >> com;
        if (com == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            st.mult(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }
    return 0;
}