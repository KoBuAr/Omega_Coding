vector <vector <char>> laberinto;

bool verificador(int x, int y){
    return x >= 0 && y >= 0 && x < laberinto.size() && y < laberinto[0].size();
}
