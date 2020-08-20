## Templates

 - `basic.cpp` is a minimalistic template for online contests like Codeforces and AtCoder
 - `template.cpp` is a lightweight template for online contests
 - `usaco.cpp` is a slightly modified version of `template.cpp` for USACO
 
### Notes
 
 - Symlink these files from the repository to your home directory so you can easily `cp ~/basic.cpp .` and `cat ~/template.cpp`
 - The line `if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);` is to redirect input and  output to files `in` and `out`, if they exist
 - For the `usaco.cpp` template, replace `name` with the name of the problem
