constexpr ll MOD = 1e9+7;

int fact[200002] = { 1 }, ifact[200002] = { 1 };

int pw(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = (ll)base * res % MOD;
		exp >>= 1;
		base = (ll)base * base % MOD;
	}
	return res;
}

int inv(int x) { return pw(x, MOD - 2); }

int nCr(int n, int k) { return (ll)fact[n] * ifact[k] % MOD * ifact[n - k] % MOD; }

for (int i = 0; i < n; ++i) {
	fact[i + 1] = (i + 1ll) * fact[i] % MOD;
	ifact[i + 1] = inv(fact[i + 1]);
}