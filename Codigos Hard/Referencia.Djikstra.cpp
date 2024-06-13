#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vp = vector<pair<int,int>>;

#define ull unsigned long long
#define ll long long
#define csp cout << " ";
#define cnl cout<<"\n"
#define nl "\n"
#define sp(x,n) fixed<<setprecision(x) << n
#define all(x) x.begin(),x.end()
#define fore(i,l,r) for(auto i=l;i<r;++i)
#define pb push_back
#define pf push_front

const int N = 1e5+1;

/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/

const ll INF = 1e18;

// grafo ponderado
struct Nodo{
  int v;
  ll dist;
};

// nodo actual y el coste para llegar
struct State{
  int u;
  ll dist;

//ordenar de menor a mayor
  bool operator<(const State& a) const{
      return !(dist < a.dist);
  }
};

// grafo, distancias, nodo de donde viene
vector<Nodo> graph[N];
vector<ll> dist(N, INF);
int from[N];

// Recuperacion de datos o el camino
void rec(int t) {
    stack <ll> recuperacion;
    
    int c = t;
    
    while(c != -1){
        recuperacion.push(c);
        c = from[c];
    }
    
    while(!recuperacion.empty()){
        cout << recuperacion.top() << " ";
        recuperacion.pop();
    }
}

void Dijkstra(int s, int t) {
  // guarda el nodo y lo que cuesta para llegar
    priority_queue<State> pq;

  // la primer distancia es desde cero
    dist[s] = 0;
    from[s] = -1;
    pq.push({s, 0});
    
    while(!pq.empty()) {
      //igualas el nodo actual y lo borras de la pila
        auto nodoActual = pq.top();
        pq.pop();

      //verificas si hay un camino mejor al actual lo ignoras
         if(nodoActual.dist > dist[nodoActual.u]) continue;

      // si llegas al final recuperas los nodos del camino
      // si necesitas la distancia cout << dist[t];
         if(nodoActual.u==t) {
             rec(t);
             return;
         }
         // calcula la nueva distancia
         for(auto& e: graph[nodoActual.u]) {
             ll newDist = nodoActual.dist + e.dist;
             if(newDist < dist[e.v]) {
                 dist[e.v] = newDist;
                 
                 pq.push({e.v, dist[e.v]});
                 from[e.v] = nodoActual.u;
             }
         }
    }
    // si no encuentra un camino imprime "-1"
    cout << "-1";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    fore(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }

  // los argumentos son de que nodo inicia hasta donde
    Dijkstra(1,n);
    
    return 0;
}
// https://codeforces.com/problemset/problem/20/C
