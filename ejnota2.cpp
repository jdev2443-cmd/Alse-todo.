#include <iostream>
using namespace std;
int main(){
    int datos[5];
    int suma =0;

    cout<<"ingrese los numeros que desea en el arreglo "<<endl;
    for(int i = 0; i < 5; i++){
        cout<<"digite los datos en orden "<<(i+1)<< ":";
        cin>>datos[i];
    }
    for(int i =0; i < 5; i++){
        cout<<"los numeros dentro del arreglo son "<< datos[i]<<endl;
        suma+=datos[i];
    }
    cout<<"la suma de los datos del arreglo es de "<<suma<<endl;
    
    return 0;

}
