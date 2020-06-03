# Complexity Table

Data Structure | Storage* | Build | Point Update | Range Update | Point Query | Range Query
--- | --- | --- | --- | --- | --- | ---
Segment Tree | O(n) | O(n) | O(log n) | O(log n) | O(log n) | O(log n)
Fenwick Tree | O(n) | O(n) | O(log n) | O(log n) | O(log n) | O(log n)
Sparse Table | O(n log n) | O(n log n) | - | - | O(1) | O(1)
Segment Tree (2D) | O(n<sup>2</sup>) | O(n) | O(log<sup>2</sup> n) | O(log<sup>2</sup> n) | O(log<sup>2</sup> n) | O(log<sup>2</sup> n)
Fenwick Tree (2D) | O(n<sup>2</sup>) | O(n) | O(log<sup>2</sup> n) | - | O(log<sup>2</sup> n) | O(log<sup>2</sup> n)
Quadtree | O(n<sup>2</sup>) | O(n) | O(log n) | O(log n) | O(log n) | O(n)

* _Without compression_
