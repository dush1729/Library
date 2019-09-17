int kmp(string &S, string &T) {
	// Generate KMP table
	vector<int> F(T.length() + 1, 0);
	F[0] = -1;
	for (int i = 0; i < T.length(); i++) {
		F[i + 1] = F[i];
		while (F[i + 1] > -1 && T[i] != T[F[i + 1]]) F[i + 1] = F[F[i + 1]];
		F[i + 1]++;
	}

	// Search
	int i = 0, j = 0;
	while (i < S.length()) {
		if (S[i] == T[j]) {
			i++, j++;
			if (j == T.length()) return i - j; // Found match
			/*if (j == T.size()) {
				ret++; // Count matches
				j = F[j];
				if (j < 0) i++, j++;
			}*/
		}
		else {
			j = F[j];
			if (j < 0) i++, j++;
		}
	}

	return -1; // Match not found
}