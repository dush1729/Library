int sieve_size;
bitset<10000001> bs;
vector<int> pr;

void sieve(int size) {
	sieve_size = size;
	bs.set(); bs[0] = bs[1] = 0;
  	for (ll i = 2; i <= sieve_size; ++i) if (bs[i]) {
		for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
		pr.push_back(i);
	}
}

bool is_prime(ll N) {
	if (N <= sieve_size) return bs[N];
	for (int i = 0; i < pr.size() && pr[i] * pr[i] <= N; ++i) if (N % pr[i] == 0) return false;
  	return true;
}

vector<int> pf(ll N) {
	vector<int> factors;
  	ll idx = 0, pf = pr[idx];
	while (N != 1 && pf * pf <= N) {
		while (N % pf == 0) { N /= pf; factors.push_back(pf); }
		pf = pr[++idx];
  	}
	if (N != 1) factors.push_back(N);
	return factors;
}

ll num_pf(ll N) {
	ll idx = 0, pf = pr[idx], ans = 0;
	while (N != 1 && pf * pf <= N)) {
		while (N % pf == 0) { N /= pf; ans++; }
		pf = pr[++idx];
  	}
  	return ans + (N != 1);
}

ll num_diff_pf(ll N) {
  	ll idx = 0, pf = pr[idx], ans = 0;
  	while (N != 1 && pf * pf <= N) {
		if (N % pf == 0) ans++;
		while (N % pf == 0) N /= pf;
		pf = pr[++idx];
  	}
  	return ans + (N != 1);
}

ll sum_pf(ll N) {
	ll idx = 0, pf = pr[idx], ans = 0;
  	while (N != 1 && pf * pf <= N)) {
		while (N % pf == 0) { N /= pf; ans += pf; }
		pf = pr[++idx];
  	}
  	return ans + (N != 1) * N;
}

ll num_div(ll N) {
	ll idx = 0, pf = pr[idx], ans = 1;
  	while (N != 1 && pf * pf <= N)) {
		ll power = 0;
		while (N % pf == 0) { N /= pf; ++power; }
		ans *= (power + 1);
		pf = pr[++idx];
  	}
  	return (N != 1) ? 2 * ans : ans;
}

ll sum_div(ll N) {
  	ll idx = 0, pf = pr[idx], ans = 1;
  	while (N != 1 && pf * pf <= N) {
		ll power = 0;
		while (N % pf == 0) { N /= pf; ++power; }
		ans *= ((ll)pow((double)pf, power + 1.0) - 1) / (pf - 1);
		pf = pr[++idx];
  	}
  	if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
  	return ans;
}

ll phi(ll N) {
	ll idx = 0, pf = pr[idx], ans = N;
	while (N != 1 && pf * pf <= N) {
		if (N % pf == 0) ans -= ans / pf;
		while (N % pf == 0) N /= pf;
		pf = pr[++idx];
	}
	return N != 1 ? ans - ans / N : ans;
}