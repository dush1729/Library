struct y_node {
	int val;
	y_node* c[2];
	y_node() { val = 0; c[0] = c[1] = 0; }
	y_node* get_c(int i) { return (!c[i] ? c[i] = new y_node : c[i]); }
	void update(int y, int v, int l = -1, int r = MN) {
		if (l == r) val += v;
		else {
			int m = (l + r) >> 1;
			y <= m ? get_c(0)->update(y, v, l, m) : get_c(1)->update(y, v, m + 1, r);
			val = (c[0] ? c[0]->val : 0) + (c[1] ? c[1]->val : 0);
		}
	}
	int query(int yl, int yr, int l = -1, int r = MN) {
		if (yl > r || yr < l) return 0;
		if (yl <= l && yr >= r) return val;
		int m = (l + r) >> 1;
		return (c[0] ? c[0]->query(yl, yr, l, m) : 0) + (c[1] ? c[1]->query(yl, yr, m + 1, r) : 0);
	}
};

struct x_node {
	y_node seg;
	x_node* c[2];
	x_node() { c[0] = c[1] = 0;}
	x_node* get_c(int i) { return (!c[i] ? c[i] = new x_node : c[i]); }
	void update(int x, int y, int v, int l = -1, int r = MN) {
		if (l == r) seg.update(y, v);
		else {
			int m = (l + r) >> 1;
			x <= m ? get_c(0)->update(x, y, v, l, m) : get_c(1)->update(x, y, v, m + 1, r);
			seg.update(y, (c[0] ? c[0]->seg.query(y, y) : 0) + (c[1] ? c[1]->seg.query(y, y) : 0));
		}
	}
	int query(int xl, int xr, int yl, int yr, int l = -1, int r = MN) {
		if (xl > r || xr < l) return 0;
		if (xl <= l && xr >= r) return seg.query(yl, yr);
		int m = (l + r) >> 1;
		return (c[0] ? c[0]->query(xl, xr, yl, yr, l, m) : 0) + (c[1] ? c[1]->query(xl, xr, yl, yr, m + 1, r) : 0);
	}
} root;