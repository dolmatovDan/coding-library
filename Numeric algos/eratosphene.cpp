#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[1] = false;
    for(int i = 2;i * i <= n;++i) {
        if (sieve[i]) {
            for(int j = i * i;j <= n;j+=i) {
                sieve[j] = false;
            }
        }
    }
    vector<int> res;
    for(int i = 1;i <= n;++i) {
        if (sieve[i]) res.push_back(i);
    }
    return res;
}

int main()
{
    return 0;
}
