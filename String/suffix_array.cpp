#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> suffix_array(string &S) {
	int N = S.length();
	vector<int> SA(N), rank(N);
	for (int i = 0; i < N; i++) {
		SA[i] = N - i - 1;
		rank[i] = S[i];
	}
	stable_sort(SA.begin(), SA.end(), [&S](int i, int j) { return S[i] < S[j]; });
	for (int t = 1; t < N; t <<= 1) {
		vector<int> tmp(rank);
		for (int i = 0; i < N; i++) {
			bool s = i && SA[i - 1] + t < N && tmp[SA[i]] == tmp[SA[i - 1]] && tmp[SA[i] + t >> 1] == tmp[SA[i - 1] + t >> 1];
			rank[SA[i]] = s ? rank[SA[i - 1]] : i;
		}
		
		tmp = SA;
		vector<int> cnt(N);
		for (int i = 0; i < N; i++) cnt[i] = i;
		for (int i = 0; i < N; i++) {
			int s = tmp[i] - t;
			if (s >= 0) SA[cnt[rank[s]]++] = s;
		}
	}
	return SA;
}
