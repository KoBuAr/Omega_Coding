#include <bits/stdc++.h>
using namespace std;

int main()
{
    // PRESENTACION MAMALONA SOBRE VECTORES //
    
    cout << "Leer e imprimir un vector con un indice asignado: \n";
    
    // Declaracion: vector <tipo de dato> nombre (cantidad de datos);
    
    cout << "Ingresa el tamaño del indice: \n";
    
    int n;
    cin >> n;
    
    vector <int> victor(n);
    
    /*  Si tiene determinado una cantidad de indices se puede asignar los valores
    directamente del vector como un areglo tipo c  dentro de un for, ejemplo: */
    
    cout << "Ahora los datos: \n";
    
    for (int i = 0; i < n; i++){
        cin >> victor[i];
    }
    
    /* Para imprimir cada dato del arreglo es el mismo proceso
    pero hay que cambiar el cin por un cout */
    
    for (int i = 0; i < n; i++){
        cout << victor[i] << " ";
    }
    
    cout << "\n";
    
    cout << "Leer e imprimir un vector sin un indice asignado: \n";
    
    // Declaracion: vector <tipo de dato> nombre;
    
    cout << "Ingresa el tamaño del vector: \n";
    
    int a;
    cin >> a;
    
    vector <int> victorjr;
    
    /* Esta parte del codigo de igual forma lee e imprime el vector pero si 
    no hay un indice determinado necesitas de un auxiliar para ingresar.
    
    El auxiliar se podria tomar como los datos que se guardaran en el vector y 
    tiene que ir de a huevo en un for */
    
    cout << "Ingresa los datos: \n";
    
    for (int i = 0; i < a; i++){
        int aux;
        cin >> aux;
        
        victorjr.push_back(aux);
    }
    
    for (int i = 0; i < a; i++){
        cout << victorjr[i] << " ";
    }
    
    cout << "\n";
    
    cout << "Borrar datos: \n";
    
    cout << "Ingresa la posicion que quieres borrar: " << "\n";
    
    int y;
    cin >> y;
    
    /* Esta parte del codigo borra una posicion en especifica del vector */
    
    victorjr.erase(victorjr.begin() + y);
    
    for (int i = 0; i < victorjr.size(); i++){
        cout << victorjr[i] << "\n";
    }
    
    cout << "Buscar datos en el vector: " << "\n";
    
    // Declara lo que vas a buscar

    int o;
    cin >> o;

    if(find(victorjr.begin(), victorjr.end(), o) != victorjr.end()){
        cout << "Encontrado"; 
    }
    else if (find(victorjr.begin(), victorjr.end(), o) == victorjr.end()){
        cout << "No se encontro";
    }
    

    return 0;
}
