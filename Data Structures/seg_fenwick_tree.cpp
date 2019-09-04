struct node {
	int val;
	node* c[2];
	node() {
		val = 0;
		c[0] = c[1] = 0;
	}
	node* get_c(int i) { return (!c[i] ? c[i] = new node : c[i]); }
	void update(int x, int v, int l = 0, int r = -1) {
		if (r == -1) r = N - 1;
		if (l == r) val += v;
		else {
			int m = (l + r) >> 1;
			x <= m ? get_c(0)->update(x, v, l, m) : get_c(1)->update(x, v, m + 1, r);
			val = (c[0] ? c[0]->val : 0) + (c[1] ? c[1]->val : 0);
		}
	}
	long long query(int a, int b, int l = 0, int r = -1) {
		if (r == -1) r = N - 1;
		if (a > r || b < l) return 0;
		if (a <= l && b >= r) return val;
		int m = (l + r) >> 1;
		return (c[0] ? c[0]->query(a, b, l, m) : 0) + (c[1] ? c[1]->query(a, b, m + 1, r) : 0);
	}
} FT[100005];

void update(int x, int y, int v) { for (; x < N; x += x & -x) FT[x].update(y, v); }
int query(int x, int y1, int y2) { int ret = 0; for (; x > 0; x -= x & -x) ret += FT[x].query(y1, y2); return ret; }
int query(int x1, int x2, int y1, int y2) { return query(x2, y1, y2) - (x1 == 1 ? 0 : query(x1 - 1, y1, y2)); }