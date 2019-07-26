class fenwick_tree_2d {
private: int N, M, vector<vector<int>> FT;
public:
    fenwick_tree_2d(int n, int m) {
        N = n + 1, M = m + 1;
        FT.resize(N, 0);
        for (int i = 0; i < N; i++) FT[i].resize(M, 0);
    }
    void update(int x, int y, int val) {
	    for (int i = x; i < N; i += i & -i) {
		    for (int j = y; j < M; j += j & -j) FT[i][j] += val;
		}
	}
    int query(int x, int y) {
	    int ret = 0;
	    for (int i = x; i > 0; i -= i & -i) {
		    for (int j = y; j > 0; j -= j & -j) ret += FT[i][j];
		}
	    return ans;
    }
}
