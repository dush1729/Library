struct tarjan {
    int cnt, scc_num, scc[MN], in[MN], low[MN];
    stack<int> s;
    bitset<MN> ins;
    void tarjan(vector<int> * G, int u) {
        low[u] = in[u] = cnt++, ins[u] = 1; s.push(u);        
        for (int v : G[u]) {
            if (in[v] == -1) tarjan(G, v), low[u] = min(low[u], low[v]);
            else if (ins[v]) low[u] = min(low[u], in[v]);
        }
        if (low[u] == in[u]) {
            while (1) {
                int x = s.top(); s.pop();
                scc[x] = scc_num, ins[x] = 0;
                if (x == u) break;
            }
            ++scc_num;
        }
    }
    void find_scc(vector<int> * G) {
        memset(scc, -1, sizeof scc), memset(in, -1, sizeof in);
        for (int u = 1; u <= N; ++u) if (scc[u] == -1) tarjan(G, u);
    }
}
