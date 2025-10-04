#include<iostream>
using namespace std;
int mcd(int num1, int num2){
    while(num2 !=0){
        int div = num1 % num2;
        num1 = num2;
        num2 = div;
    }
    return num1;
}


int main(){
    int num1, num2;
    cout<<"ingrese el primer numero "<<endl;
    cin>>num1;

    cout<<"ingrese el segundo numero "<<endl;
    cin>>num2;

    cout<<"el MCD de los numeros ingresados es de "<<mcd(num1,num2)<<endl;
    return 0;

}