bool busc(vector <int> & a, int & s){
  int inicio = 0, fin = a.size()-1, medio;

  while(inicio <= fin){
    medio = (inicio + fin) / 2;
    
    if (s == a[medio]) return 1;

    else if (s > a[medio]) inicio = medio + 1;
    
    else if (s < a[medio]) fin = medio - 1;

  }
  return 0;
}
