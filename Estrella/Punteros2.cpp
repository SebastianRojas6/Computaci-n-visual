#include<iostream>
using namespace std;

int main(){

    int  x[] = {1,2,3,4};
    
    int *dir_x;

    dir_x = &x[0];

    for(int i=0; i<4 ;i++){

        cout<<"Hola ["<<i<<"] "<< *dir_x++<<endl;

    }

}