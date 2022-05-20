#include <bits/stdc++.h>
using namespace std;
#define len(a) (int)(a.size())

vector<int> z_func(string s) {
    int n = len(s);
    vector<int> z(n);
    z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

signed main()
{
    return 0;
}
