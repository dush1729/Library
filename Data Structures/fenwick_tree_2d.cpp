#include <vector>
using namespace std;

class fenwick_tree_2d {
private: int N, M; vector<vector<int>> FT;
public:
	fenwick_tree_2d(int n, int m) {
		N = n + 1, M = m + 1;
		FT.resize(N);
		for (int i = 0; i < N; i++) FT[i].resize(M, 0);
	}
	void update(int x, int y, int val) {
		for (; x < N; x += x & -x) {
			for (; y < M; y += y & -y) FT[x][y] += val;
		}
	}
	int query(int x, int y) {
		int ret = 0;
		for (; x > 0; x -= x & -x) {
			for (; y > 0; y -= y & -y) ret += FT[x][y];
		}
		return ret;
	}
	int query(int xl, int xr, int yl, int yr) {
		return query(xr, yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);
	}
};
