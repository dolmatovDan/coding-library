#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Операция должна быть ассоциотивной, коммутативной и дистрибутивной.

ll NEUTRAL_EL = 0;
const ll MOD = 1e9 + 7;
struct node
{
	ll mult;
	ll sum;
};

vector<node> t;
int n;
ll op_modify(ll a, ll b) {
	return (a * b) % MOD;
}
ll op_sum(ll a, ll b) {
	return (a + b) % MOD;
}

void build(int v = 0, int tl = 0, int tr = n) {
	if (tl + 1 == tr) {
		t[v].mult = 1;
		t[v].sum = 1;
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm, tr);
	t[v].sum = op_sum(t[v * 2 + 1].sum, t[v * 2 + 2].sum);
	t[v].mult = 1;
}

void mult(int l, int r, int x, int v = 0, int tl = 0, int tr = n) {
	if (l >= tr or r <= tl) {
		return;
	}
	if (l <= tl and r >= tr) {
		t[v].mult = op_modify(t[v].mult, x);
		t[v].sum = op_modify(t[v].sum, x);
		return;
	}
	int tm = (tl + tr) / 2;
	mult(l, r, x, v * 2 + 1, tl, tm);
	mult(l, r, x, v * 2 + 2, tm, tr);
	t[v].sum = op_sum(t[v * 2 + 1].sum, t[v * 2 + 2].sum);
	t[v].sum = op_modify(t[v].sum, t[v].mult);
}

ll sum(int l, int r, int v = 0, int tl = 0, int tr = n) {
	if (l >= tr or r <= tl) {
		return NEUTRAL_EL;
	}
	if (tl >= l and tr <= r) {
		return t[v].sum;
	}
	int tm = (tl + tr) / 2;
	ll m1 = sum(l, r, v * 2 + 1, tl, tm);
	ll m2 = sum(l, r, v * 2 + 2, tm, tr);
	ll res = op_sum(m1, m2);
	return op_modify(res, t[v].mult);
}

signed main() {
	return 0;
}