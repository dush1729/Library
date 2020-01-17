template <class BidirectionalIterator> // Coordinate compression
void compress(BidirectionalIterator first, BidirectionalIterator last) {
	vector<auto> tmp(first, last);
	sort(tmp.begin(), tmp.end());
	tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
	for (auto it = first; it != last; it++) *it = lower_bound(tmp.begin(), tmp.end(), *it) - tmp.begin();
}
