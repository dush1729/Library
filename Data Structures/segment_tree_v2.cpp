template< typename T > class seg_tree {
private:
	int N;
	vector<T> seg, tmp;
public:
	seg_tree(int size) {
		N = size;
		seg.resize(4 * N, 0);
	}
	seg_tree(int size, T A[]) {
		N = size;
		seg.resize(4 * N);
		build(A);
	}
	seg_tree(vector<T>& A) {
		N = A.size();
		seg.resize(4 * N);
		build(A);
	}
	void pull(int n) { seg[n] = seg[n << 1] + seg[n << 1 | 1]; }
	void push(int l, int r, int n) {
		seg[n] = (r - l + 1) * tmp[n];
		if (l != r) tmp[n << 1] += tmp[n], tmp[n << 1 | 1] += tmp[n];
		tmp[n] = 0;
	}
	void build(T A[], int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N - 1;
		if (l == r) seg[n] = A[l];
		else {
			int m = (l + r) >> 1;
			build(A, l, m, n << 1), build(A, m + 1, r, n << 1 | 1);
			pull(n);
		}
	}
	void build(vector<T>& A, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N - 1;
		if (l == r) seg[n] = A[l];
		else {
			int m = (l + r) >> 1;
			build(A, l, m, n << 1);
			build(A, m + 1, r, n << 1 | 1);
			pull(n);
		}
	}
	void update(int x, T v, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N - 1;
		if (l == r) seg[n] += v;
		else {
			int m = (l + r) >> 1;
			x <= m ? update(x, v, l, m, n << 1) : update(x, v, m + 1, r, n << 1 | 1);
			pull(n);
		}
	}
	void update(int a, int b, T v, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N - 1;
		push(n, l, r);
		if (l > b || r < a) return;
		if (l >= a && r <= b) {
			tmp[n] = v;
			push(n, l, r);
		}
		else {
			int m = (l + r) >> 1;
			update(a, b, v, l, m, n << 1), update(a, b, v, m + 1, r, n << 1 | 1);
			pull(n);
		}
	}
	T query(int a, int b, int l = 0, int r = -1, int n = 1) {
		if (r == -1) r = N - 1;
		if (l > b || r < a) return 0;
		push(n, l, r);
		if (l >= a && r <= b) return seg[n];
		int m = (l + r) >> 1;
		return query(a, b, l, m, n << 1) + query(a, b, m + 1, r, n << 1 | 1);
	}
};