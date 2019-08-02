class sparse_table {
private: int st[20][100000];
public:
	int log(int x) { return 32 - __builtin_clz(x) - 1; }

	sparse_table(int N, int A[]) {
		for (int i = 0; i < N; i++) st[i][0] = A[i];
		for (int i = 0; i <= log(N); i++) {
			for (int j = 0; j + (1 << i) < N; j++) st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}

	int query(int i, int j) {
		int k = log(j - i + 1);
		return min(st[k][i], st[k][j - (1 << k) + 1]);
	}
};
