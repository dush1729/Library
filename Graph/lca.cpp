int d[MX], L[MX][20];
void dfs(int u = 1, int p = 0) {
	d[u] = d[p] + 1, L[u][0] = p;
	for (int i = 0; i < 18 && L[u][i]; i++) L[u][i+1] = L[L[u][i]][i];
	for (auto & v : G[u]) if (v != p) dfs(v, u);
}
int lca(int u, int v) {
	if (d[u] > d[v]) swap(u, v);
	for (int i = 18; i >= 0; --i) if (d[v] - (1<<i) >= d[u]) v = L[v][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; --i) if (L[u][i] && L[u][i] != L[v][i]) u = L[u][i], v = L[v][i];
	return L[u][0];
}
inline int dist(int u, int v) { return d[u]+d[v]-2*d[lca(u, v)]; }
