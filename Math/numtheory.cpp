constexpr ll MOD = 1e9+7;

int pow(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = ((ll)base * res) % MOD;
		exp >>= 1;
		base = ((ll)base * base) % MOD;
	}
	return res;
}

int inv(int x) { return pow(x, MOD - 2); }
