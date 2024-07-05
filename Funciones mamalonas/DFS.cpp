const int N = 1e5 + 5;
// Grafo, con lista de adyacencia
vector<int> graph[N];
// Arreglo de los nodos ya visitados, para evitar bucles
bool vis[N];

void DFS(int u) {
    // a cada noodo que se le aplique DFS, se marca como visitado
    vis[u] = true;

    // vemos los vecinos del nodo actual
    for(auto v:graph[u]) {
        // y si no lo hemos visto
        if(!vis[v]) 
            DFS(v); // hacemos la dfs
    }
}
