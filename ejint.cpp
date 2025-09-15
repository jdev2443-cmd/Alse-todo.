#include <iostream>
int main(){
    int num1, num2, suma, resta, multiplicacion, division;

    std::cout<<"ingrese el valor 1 ";
    std::cin>>num1;

    std::cout<<"ingrse el valor 2 ";
    std::cin>>num2;
    
    
    suma = num1 + num2;
    std::cout <<"la suma es "<< suma;

    resta = num1 - num2;
    std::cout<<"la resta de los numeros es "<< resta;

    multiplicacion = num1 * num2;
    std::cout<<"la multiplicacion de los numeros es "<<multiplicacion;

    division = num1 / num2;
    std::cout<<"la division de los numeros es "<< division;
 
    return 0;

}