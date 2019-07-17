#include <algorithm>
#include <iostream>
#include <climits>
#include <tuple>
#include <cmath>
using namespace std;
constexpr auto EPS = numeric_limits<double>::epsilon();

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

struct line {
	int a, b, c;
	bool operator < (const line& l) const {
		return tie(a, b, c) < tie(l.a, l.b, l.c);
	}
};

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

line points_to_line(point p1, point p2) {
	int a = p2.y - p1.y, b = p1.x - p2.x, c = p1.y * p2.x - p1.x * p2.y;
	int d = gcd(gcd(abs(a), abs(b)), abs(c));
	return { a / d, b / d, c / d };
}

double point_to_line(point p, line l) {
	return abs(l.a * p.x + l.b * p.y + l.c) / hypot(l.a, l.b);
}

line perp_bi(point p1, point p2) {
	int a = 2 * (p2.x - p1.x), b = 2 * (p2.y - p1.y), c = -a * (p1.x + p2.x) / 2 - b * (p1.y + p2.y) / 2;
	int d = gcd(gcd(abs(a), abs(b)), abs(c));
	return { a / d, b / d, c / d };
}

point reflect(point p, line l) {
	int x = p.x * (l.b * l.b - l.a * l.a) - 2 * l.a * (l.b * p.y + l.c);
	int y = p.y * (l.a * l.a - l.b * l.b) - 2 * l.b * (l.a * p.x + l.c);
	int d = l.a * l.a + l.b * l.b;
	if (x % d && y % d) return { 10001, 10001 };
	else return { x / d, y / d };
}

struct seg {
	point p1, p2;
	seg(point _p1, point _p2) : p1(_p1), p2(_p2) {}
};

line seg_to_line(seg s) {
	return points_to_line(s.p1, s.p2);
}

double point_to_seg(point p, seg s) {
	int a = norm_sq(to_vec(s.p1, s.p2)), b = norm_sq(to_vec(p, s.p1)), c = norm_sq(to_vec(p, s.p2));
	if (a + b > c && a + c > b) return point_to_line(p, seg_to_line(s));
	else return min(dist(p, s.p1), dist(p, s.p2));
}

bool seg_isect(seg a, seg b) {
	return ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2) <= 0 && ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2) <= 0);
}
