#include<iostream>

using namespace std;

int main() {
    int x[10];
    int *dir_x;
    int y[10]; 
    int contador = 0;

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> x[i];
        dir_x = &x[i];

        if (*dir_x % 2 == 0) {
            y[contador] = *dir_x;
            contador++;
        }
    }

    cout << "\nLos numeros pares ingresados son:\n";
    for (int i = 0; i < contador; i++) {
        cout << "El numero[" << i << "] es: " << y[i] << endl;
        cout << "Su direccion de memoria es: " << &y[i] << endl; // Corregimos la dirección de memoria
    }

    return 0;
}
