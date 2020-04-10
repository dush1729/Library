constexpr ll MOD = 1e9+7;

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
