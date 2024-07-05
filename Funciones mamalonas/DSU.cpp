struct DSU{
    vector<int> pr, frds;
    int groups;
    
    DSU(int n): pr(n+1), groups(n), frds(n+1, 1) {
        iota(all(pr), 0);
    }
    
    int find(int u) {
        return pr[u]==u ? u: find(pr[u]);
    }
    
    void unite(int u, int v) {
        u = find(u), v = find(v);
        
        if(u!=v) {
            if(frds[u] < frds[v]) 
                swap(u, v);
                
            frds[u]+= frds[v];
            pr[v] = u;
            groups--;
        }
    }
    
    bool areFriends(int u, int v) {
        return find(u)==find(v);
    }
    
    int getFriends(int u) {
        return frds[find(u)];
    }
};
