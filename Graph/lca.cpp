int d[50005] = { 0 }, L[20][50005] = { 0 };
vector<int> G[50005];

void dfs(int u, int p) {
	d[u] = d[p] + 1;
	L[0][u] = p;
	for (int i = 0; (1 << i) < N; i++) if (L[i][u]) L[i + 1][u] = L[i][L[i][u]];
	for (int v : G[u]) if (v != p) dfs(v, u);
}

int lca(int u, int v) {
	if (d[u] > d[v]) swap(u, v);
	for (int i = log2(N); i >= 0; i--) if (d[v] - (1 << i) >= d[u]) v = L[i][v];
	if (u == v) return u;
	for (int i = log2(N); i >= 0; i--) if (L[i][u] && L[i][u] != L[i][v]) u = L[i][u], v = L[i][v];
	return L[0][u];
}
