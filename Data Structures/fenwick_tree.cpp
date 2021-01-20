template<typename T> class fenwick_tree {
private: int N; T FT[MX];
public:
	fenwick_tree(int n) { N = n; }
	fenwick_tree(int n, T A[]) { N = n; memcpy(FT, A, sizeof FT); }
	void update(int x, T val) { if (++x) for (; x < N; x += x&-x) FT[x] += val; }
	T query(int x) { T ret = 0; if (++x) for (; x; x -= x&-x) ret += FT[x]; return ret; }
	T query(int x, int y) { return query(y)-query(x-1); }
};
