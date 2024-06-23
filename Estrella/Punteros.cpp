//Comprobar si un número es par o impar con punteros, señalar en qué posición de memoria se encuentra

#include<iostream>

using namespace std;

int main(){

    int a, *dir_a;

    cin>>a;


    dir_a = &a;

    if(*dir_a % 2 == 0){

        cout<<"Es par";
        cout<<"El numero es: "<<*dir_a;
        cout<<"La direccion de memoria es: "<<dir_a<<endl;
        cout<<&a;
    }

    else{
        cout<<"No es par"<<endl;
         cout<<"El numero es: "<<*dir_a;
        cout<<"La direccion de memoria es: "<<dir_a<<endl;
        cout<<&a;
    }

    return 0;
}