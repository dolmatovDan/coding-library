#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
struct dsu {
    int size;
    vector<int> p, r;
    void init(int n) {
        size = n;
        p.assign(n, 0);
        iota(all(p), 0);
        r.assign(n, 1);
    }
    int get(int a) {
        if (a == p[a]) {
            return a;
        }
        p[a] = get(p[a]);
        return p[a];
    }

    void join(int _a, int _b) {
        int a = get(_a);
        int b = get(_b);
        if (r[a] == r[b]) r[a]++;
        if (r[a] > r[b]) {
            p[b] = a;
        } else {
            p[a] = b;
        }
    }
};

signed main()
{
    return 0;
}