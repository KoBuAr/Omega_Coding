struct Graph{
    struct Edge{
        int src;
        int dest;
        int weight;
    };

    int V;
    vector<Edge> edges;
    vi pr;

    Graph(int v): pr(v), V(v) {
        iota(all(pr), 0);
    }

    void addEdge(int src, int dest, int weight) {
        edges.pb({src, dest, weight});
    }

    int find(int u) {
        return pr[u] == u ? u: find(pr[u]);
    }

    void MST() {
        vector<Edge> result;
        sort(all(edges), [&] (Edge a, Edge b) {
            return a.weight < b.weight;
        });

        for(auto& edge: edges) {
            int u = find(edge.src);
            int v = find(edge.dest);

            if(u!=v) {
                pr[v] = u;
                result.pb(edge);
            }
        }

        for(auto& edge: result) 
            cout << edge.src << " -> " << edge.dest << " == " << edge.weight << nl;
    }
};
