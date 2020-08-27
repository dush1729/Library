template<typename BidirectionalIterator> // Coordinate compression
void compress(BidirectionalIterator first, BidirectionalIterator last) {
    vector<pair<BidirectionalIterator, int>> tmp;
    for (auto it = first; it != last; ++it) tmp.emplace_back(*it, it-first);
    sort(begin(tmp), end(tmp));
    for (auto it = begin(tmp); it != end(tmp); ++it) (first+it->s) = it-begin(tmp);
}
