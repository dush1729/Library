template<typename T> class fenwick_tree_2d {
private: int N, M; vector<vector<T>> FT;
public:
	fenwick_tree_2d(int n, int m) {
		N = n + 1, M = m + 1;
		FT.resize(N);
		for (int i = 0; i < N; i++) FT[i].resize(M, 0);
	}
	void update(int x, int y, T val) {
		for (int i = x; i < N; i += i & -i) {
			for (int j = y; j < M; j += j & -j) FT[i][j] += val;
		}
	}
	T query(int x, int y) {
		T ret = 0;
		for (int i = x; i > 0; i -= i & -i) {
			for (int j = y; j > 0; j -= j & -j) ret += FT[i][j];
		}
		return ret;
	}
	T query(int xl, int xr, int yl, int yr) {
		return query(xr, yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);
	}
};