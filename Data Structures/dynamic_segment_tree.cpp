struct node {
	int val; node* c[2];
	node() { val = 0; c[0] = c[1] = 0; }
	node* get_c(int i) { return (!c[i] ? c[i] = new node : c[i]); }
	void update(int x, int v, int l, int r) {
		if (l == r) val += v;
		else {
			int m = (l + r) >> 1;
			x <= m ? get_c(0)->update(x, v, l, m) : get_c(1)->update(x, v, m + 1, r);
			val = (c[0] ? c[0]->val : 0) + (c[1] ? c[1]->val : 0);
		}
	}
	int query(int a, int b, int l, int r) {
		if (a > r || b < l) return 0;
		if (a <= l && b >= r) return val;
		int m = (l + r) >> 1;
		return (c[0] ? c[0]->query(a, b, l, m) : 0) + (c[1] ? c[1]->query(a, b, m + 1, r) : 0);
	}
};