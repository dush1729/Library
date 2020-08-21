struct centroid {
    int sz[MN], cpar[MN];
    bitset<MN> vis;
	void dfs(vector<int> * G, int u, int p = 0) {
		sz[u] = 1;
		for (int v : G[u]) if (v != p && !vis[v]) dfs(G, v, u), sz[u] += sz[v];
	}
	int centroid(vector<int> * G, int u) {
		dfs(G, u);
		int num = sz[u], p = 0;
		do {
			int nxt = 0;
			for (int v : G[u]) if (v != p && !vis[v] && 2*sz[v] > num) nxt = v;
			p = u, u = nxt;
		} while (u);
		return p;
	}
	void centroid_decomp(vector<int> * G, int u = 1, int p = 0) {
		int c = centroid(G, u);
		vis[c] = 1,	cpar[c] = p;
		for (int v : G[c]) if (!vis[v]) centroid_decomp(G, v, c);
	}
} 
