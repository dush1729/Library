#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
constexpr int MX = MX;

ordered_set<int> S[4 * MX];

void update(int x, int y, int l = 0, int r = MX, int n = 1) {
	if (l != r) {
		int m = (l + r) >> 1;
		x <= m ? update(x, y, l, m, n << 1) : update(x, y, m + 1, r, n << 1 | 1);
	}
	S[n].insert(y);
}

int query(int xl, int xr, int yl, int yr, int l = 0, int r = MX, int n = 1) {
	if (l > r || l > xr || r < xl) return 0;
	if (l >= xl && r <= xr) return S[n].order_of_key(yr + 1) - S[n].order_of_key(yl);
	else {
		int m = (l + r) >> 1;
		return query(xl, xr, yl, yr, l, m, n << 1) + query(xl, xr, yl, yr, m + 1, r, n << 1 | 1);
	}
}