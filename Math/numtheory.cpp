constexpr ll MOD = 1e9+7;

ll fact[MN] = { 1 }, ifact[MN] = { 1 };

inline ll pw(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp & 1) (res *= base) %= MOD;
		exp >>= 1, (base *= base) %= MOD;
	}
	return res;
}

inline ll inv(ll x) { return pw(x, MOD - 2); }

inline ll nCr(int n, int k) { return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD; }

for (int i = 0; i < N; ++i) {
	fact[i + 1] = (i + 1ll) * fact[i] % MOD;
	ifact[i + 1] = inv(fact[i + 1]);
}
