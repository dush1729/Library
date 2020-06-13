int d[100001], L[100001][20];
vector<int> G[100001];

void dfs(int u = 1, int p = 0) {
	d[u] = d[p] + 1;
	L[u][0] = p;
	for (int i = 0; i < 16 && L[u][i]; i++) L[u][i + 1] = L[L[u][i]][i];
	for (auto& v : G[u]) if (v != p) dfs(v, u);
}

int lca(int u, int v) {
	if (d[u] > d[v]) swap(u, v);
	for (int i = 16; i >= 0; i--) if (d[v] - (1 << i) >= d[u]) v = L[v][i];
	if (u == v) return u;
	for (int i = 16; i >= 0; i--) if (L[u][i] && L[u][i] != L[v][i]) u = L[u][i], v = L[v][i];
	return L[u][0];
}