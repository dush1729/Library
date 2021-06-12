constexpr ll MOD = 1e9+7;

inline ll pw(ll base, ll exp) {
	ll res = 1;
	while (exp) {
		if (exp & 1) (res *= base) %= MOD;
		exp >>= 1, (base *= base) %= MOD;
	}
	return res;
}
inline ll inv(ll x) { return pw(x, MOD-2); }

ll fact[MX] = { 1 }, ifact[MX] = { 1 };
inline ll nCr(int n, int k) { return fact[n]*ifact[k]%MOD*ifact[n-k]%MOD; }


for (int i = 1; i < N; ++i) fact[i] = i*fact[i-1]%MOD, ifact[i] = inv(fact[i]);
