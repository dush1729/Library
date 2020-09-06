template<typename T> struct seg_tree {
	T seg[4*MX], tmp[4*MX];
	inline T pull(const T & a, const T & b) { return a+b; }
	inline void push(int l, int r, int n) {
		seg[n] += (r-l+1)*tmp[n];
		if (l != r) tmp[n<<1] += tmp[n], tmp[n<<1|1] += tmp[n];
		tmp[n] = 0;
	}
	void build(T v, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N-1;
		if (l == r) seg[n] = v;
		else {
			int m = (l+r)>>1;
			build(v, l, m, n<<1), build(v, m+1, r, n<<1|1);
			seg[n] = pull(seg[n<<1], seg[n<<1|1]);
		}
	}
	void update(int x, T v, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N-1;
		if (l == r) seg[n] += v;
		else {
			int m = (l+r)>>1;
			x <= m ? update(x, v, l, m, n<<1) : update(x, v, m+1, r, n<<1|1);
			seg[n] = pull(seg[n<<1], seg[n<<1|1]);
		}
	}
	void update(int a, int b, T v, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N-1;
		push(l, r, n);
		if (l > r || l > b || r < a) return;
		if (l >= a && r <= b) {
			tmp[n] += v;
			push(l, r, n);
		}
		else {
			int m = (l+r)>>1;
			update(a, b, v, l, m, n<<1), update(a, b, v, m+1, r, n<<1|1);
			seg[n] = pull(seg[n<<1], seg[n<<1|1]);
		}
	}
	T query(int a, int b, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N - 1;
		if (a > b || l > b || r < a) return 0;
		push(l, r, n);
		if (l >= a && r <= b) return seg[n];
		int m = (l+r)>>1;
		return pull(query(a, b, l, m, n<<1), query(a, b, m+1, r, n<<1|1));
	}
};
