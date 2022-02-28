#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i = 0; i < n; i++)
#define int long long

typedef vector<int>     vi;

const int MOD = 1000000007;
const int MAX = 1000000000;
vi power;
int x = 51;

vi get_prefs(string s) {
    int n = (s.size());
    vi h(n + 1);
    h[0] = 0;
    fo(i, n) {
        h[i + 1] = (((h[i] * x) % MOD + MOD) % MOD + (s[i] - 'A' + 1)) % MOD;
    }
    return h;
}

int get_hash(vi &h, int l, int r) { //l, r - индексы с 1
    return (h[r] - h[l - 1] * power[r - l + 1] % MOD + MOD) % MOD;                                                               
}

void solve() { //подключить long'и
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