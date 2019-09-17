template<typename T> class fenwick_tree {
private: vector<T> FT;
public:
	fenwick_tree(int N) { FT.assign(N + 1, 0); }
	void update(int x, T val) { if (x > 0) for (; x < FT.size(); x += x & -x) FT[x] += val; }
	T query(int x) { T ret = 0; if (x > 0) for (; x > 0; x -= x & -x) ret += FT[x]; return ret; }
	T query(int x, int y) { return query(y) - (x == 1 ? 0 : query(x - 1)); }
};