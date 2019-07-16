#include <vector>
using namespace std;

class fenwick_tree {
private: vector<int> FT;
public:
	fenwick_tree(int N) { FT.assign(N + 1, 0); }
	void update(int x, int val) { for (; x < FT.size(); x += x & -x) FT[x] += val; }
	int query(int x) { int ret = 0; for (; x > 0; x -= x & -x) ret += FT[x]; return ret; }
	int query(int x, int y) { return query(y) - (x == 1 ? 0 : query(x - 1)); }
};
