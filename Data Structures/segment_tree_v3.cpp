int seg[400004], tmp[400004];
inline int pull(const int& l, const int& r) { return l + r; }
inline void push(int l, int r, int n) {
	seg[n] += (r - l + 1) * tmp[n];
	if (l != r) tmp[n << 1] += tmp[n], tmp[n << 1 | 1] += tmp[n];
	tmp[n] = 0;
}
void update(int a, int b, int v, int l = 0, int r = -1, int n = 1) {
	if (r == -1) r = N - 1;
	if (tmp[n]) push(l, r, n);
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		tmp[n] += v;
		push(l, r, n);
	}
	else {
		int m = (l + r) >> 1;
		update(a, b, v, l, m, n << 1), update(a, b, v, m + 1, r, n << 1 | 1);
		seg[n] = pull(seg[n << 1], seg[n << 1 | 1]);
	}
}
int query(int a, int b, int l = 0, int r = -1, int n = 1) {
	if (r == -1) r = N - 1;
	if (a > b || l > b || r < a) return 0;
	if (tmp[n]) push(l, r, n);
	if (l >= a && r <= b) return seg[n];
	int m = (l + r) >> 1;
	return pull(query(a, b, l, m, n << 1), query(a, b, m + 1, r, n << 1 | 1));
}