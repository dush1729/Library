struct node {
    int val;
    node* c[4];
    node() { val = 0, c[0] = c[1] = c[2] = c[3] = 0; }
	node* get_c(int i) { return (!c[i] ? c[i] = new node : c[i]); }
	void update(int x, int y, int v, int xl = 0, int xh = 200005, int yl = 0, int yh = 200005) {
		if (xl == xh && yl == yh) val = v;
		else {
			int xm = (xl + xh) / 2, ym = (yl + yh) / 2;
			if (x <= xm) {
			    if (y <= ym) get_c(0)->update(x, y, v, xl, xm, yl, ym);
			    else get_c(1)->update(x, y, v, xl, xm, ym + 1, yh);
			}
			else {
			    if (y <= ym) get_c(2)->update(x, y, v, xm + 1, xh, yl, ym);
			    else get_c(3)->update(x, y, v, xm + 1, xh, ym + 1, yh);
			}
			val = max((c[0] ? c[0]->val : 0), val);
			val = max((c[1] ? c[1]->val : 0), val);
			val = max((c[2] ? c[2]->val : 0), val);
			val = max((c[3] ? c[3]->val : 0), val);
		}
	}
	int query(int xa, int xb, int ya, int yb, int xl = 0, int xh = 200005, int yl = 0, int yh = 200005) {
	    if (xl > xb || xh < xa || yl > yb || yh < ya) return 0;
		if (xl >= xa && xh <= xb && yl >= ya && yh <= yb) return val;
		int xm = (xl + xh) / 2, ym = (yl + yh) / 2, ret = 0;
		ret = max((c[0] ? c[0]->query(xa, xb, ya, yb, xl, xm, yl, ym) : 0), ret);
		ret = max((c[1] ? c[1]->query(xa, xb, ya, yb, xl, xm, ym + 1, yh) : 0), ret);
		ret = max((c[2] ? c[2]->query(xa, xb, ya, yb, xm + 1, xh, yl, ym) : 0), ret);
		ret = max((c[3] ? c[3]->query(xa, xb, ya, yb, xm + 1, xh, ym + 1, yh) : 0), ret);
		return ret;
	}
} root;
