struct point {
	ll x, y;
	point() { x = y = 0; }
	point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator < (point p) const { return (x == p.x && y < p.y) || x < p.x; }
	bool operator == (point p) const { return x == p.x && y == p.y; }
};

double dist(point& p1, point& p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

struct vec {
	ll x, y;
	vec(ll _x, ll _y) : x(_x), y(_y) {}
	vec(point a, point b) { x = b.x - a.x, y = b.y - a.y; }
};

ll dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }

ll norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

ll cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

double angle(point a, point o, point b) {
	vec oa(o, a), ob(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool ccw(point p, point q, point r) { return cross(vec(p, q), vec(p, r)) > 0; }

bool in_polygon(point pt, const vector<point> & P) {
	double sum = 0;
	for (int i = 0; i < P.size() - 1; i++) {
		if (pt == P[i]) return true;
		ccw(pt, P[i], P[i + 1]) ? sum += angle(P[i], pt, P[i + 1]) : sum -= angle(P[i], pt, P[i + 1]);
	}
	return fabs(sum) > acos(-1.0);
}

ll area(const vector<point> & P) {
	ll res = 0;
	for (int i = 0; i < (int)P.size() - 1; i++) res += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
	return res;
	// return res / 2.0;
}

vector<point> convex_hull(vector<point> & P) {
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
