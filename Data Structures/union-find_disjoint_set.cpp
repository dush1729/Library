#include <vector>
using namespace std;

class UFDS {
private: int num_sets; vector<int> p, rank, size;
public:
	UFDS(int N) {
		num_sets = N;
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
		rank.assign(N, 0);
		size.assign(N, 1);
	}
	int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
	bool same_set(int i, int j) { return find_set(i) == find_set(j); }
	int sets() { return num_sets; }
	int size_set(int i) { return size[find_set(i)]; }
	void union_set(int i, int j) {
		if (same_set(i, j)) return;
		int x = find_set(i), y = find_set(j);
		if (rank[x] > rank[y]) swap(x, y);
		p[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
		size[y] += size[x];
		--num_sets;
	}
};
