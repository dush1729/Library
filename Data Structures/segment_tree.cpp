using namespace std;
constexpr auto MAX_N = 100005;

int A[MAX_N], seg[4 * MAX_N], tmp[4 * MAX_N];

void build(int node, int start, int end) {
	if (start == end) seg[node] = A[start];
	else {
		int mid = (start + end) >> 1;
		build(node << 1, start, mid);
		build((node << 1) + 1, mid + 1, end);
		seg[node] = seg[node << 1] + seg[(node << 1) + 1];
	}
}

void update(int node, int start, int end, int idx, int val) {
	if (start == end) seg[node] += val;
	else {
		int mid = (start + end) >> 1;
		(start <= idx && idx <= mid) ? update((node << 1), start, mid, idx, val) : update((node << 1) + 1, mid + 1, end, idx, val);
		seg[node] = seg[node << 1] + seg[(node << 1) + 1];
	}
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return seg[node];
	int mid = (start + end) >> 1;
	return query(node << 1, start, mid, left, right) + query((node << 1) + 1, mid + 1, end, left, right);
}

void update_range(int node, int start, int end, int left, int right, int val) {
	if (tmp[node]) {
		seg[node] += (end - start + 1) * tmp[node];
		if (start != end) {
			tmp[node << 1] += tmp[node];
			tmp[(node << 1) + 1] += tmp[node];
		}
		tmp[node] = 0;
	}
	if (start > end || left > end || right < start) return;
	if (left <= start && right >= end) {
		seg[node] += (end - start + 1) * val;
		if (start != end) {
			tmp[node << 1] += val;
			tmp[(node << 1) + 1] += val;
		}
	}
	else {
		int mid = (start + end) >> 1;
		update_range(node << 1, start, mid, left, right, val);
		update_range((node << 1) + 1, mid + 1, end, left, right, val);
		seg[node] = seg[node << 1] + seg[(node << 1) + 1];
	}
}

int query_range(int node, int start, int end, int left, int right) {
	if (start > end || left > end || right < start) return 0;
	if (tmp[node]) {
		seg[node] += (end - start + 1) * tmp[node];
		if (start != end) {
			tmp[node << 1] += tmp[node];
			tmp[(node << 1) + 1] += tmp[node];
		}
		tmp[node] = 0;
	}
	if (left <= start && right >= end) return seg[node];
	int mid = (start + end) >> 1;
	return query_range(node << 1, start, mid, left, right) + query_range((node << 1) + 1, mid + 1, end, left, right);
}
