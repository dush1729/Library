struct point {
	int x, y;
	point() { x = y = 0; }
	point(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (point p) const {
		return (x == p.x && y < p.y) || x < p.x;
	}
	bool operator == (point p) const {
		return x == p.x && y == p.y;
	}
};

double dist(point& p1, point& p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec {
	int x, y;
	vec(int _x, int _y) : x(_x), y(_y) {}
};

vec to_vec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

int dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

int norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

int cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
	return cross(to_vec(p, q), to_vec(p, r)) > 0;
}

double angle(point a, point o, point b) {
	vec oa = to_vec(o, a), ob = to_vec(o, b);
	return acos(dot(oa, ob) / (sqrt(norm_sq(oa)) * sqrt(norm_sq(ob))));
}

bool in_polygon(point pt, const vector<point>& P) {
	double sum = 0;
	for (int i = 0; i < P.size() - 1; i++) {
		if (pt == P[i]) return true;
		if (ccw(pt, P[i], P[i + 1])) sum += angle(P[i], pt, P[i + 1]);
		else sum -= angle(P[i], pt, P[i + 1]);
	}
	return fabs(sum) > acos(-1.0);
}

double area(const vector<point>& P) {
	int res = 0;
	for (int i = 0; i < (int)P.size() - 1; i++)	res += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
	return res / 2.0;
}

vector<point> convex_hull(vector<point>& P) {
	int n = P.size(), k = 0;
	vector<point> H(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; i++) {
		while (k >= 2 && ccw(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && ccw(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}
