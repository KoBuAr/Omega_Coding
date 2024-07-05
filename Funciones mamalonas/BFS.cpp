vc victor[N]; // lista de adyacencia
int dis[N]; // distancia entre nodos
bool vis[N]; // verificacion de si ya pasamos por ese nodo 

void BFS(int s){
    queue <int> nodos; // queue que maneja la BFS en cada nodo
    
    nodos.push(s); // entra el nodo
    vis[s] = 1; // marca como visitado
    
    while(!nodos.empty()){
        int u=nodos.front(); // toma el nodo al frente de la cola
        nodos.pop(); // y lo borra
        
        for (auto v : victor[u]){
            if(!vis[v]){ // verifica si se no se a visitado
                vis[v] = 1; // si no lo marca como visitado
                dis[v] = dis[u]+1; // actualiza la distancia que toma llegar al nodo actual más uno
                nodos.push(v);//  lo agrega a la cola
            }
        }
    }
}
