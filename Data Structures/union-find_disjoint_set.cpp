class UFDS {
private: vector<int> p, rank;
public:
	UFDS(int N) {
		p.assign(N + 1, 0);
		for (int i = 0; i <= N; i++) p[i] = i;
		rank.assign(N + 1, 0);
	}
	int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
	bool same_set(int i, int j) { return find_set(i) == find_set(j); }
	void union_set(int i, int j) {
		int x = find_set(i), y = find_set(j);
		if (x == y) return;
		rank[x] > rank[y] ? p[y] = x : p[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
 	}
};