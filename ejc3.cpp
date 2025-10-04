#include <iostream>
#include <cstdlib>

using namespace std;

double calcula_media(double a, double b) {
    return (a + b) / 2.0;
}

int main()
{
int num1,num2;
std::cout<<"ingrese un valor"<<std::endl;
std::cin>>num1;
if(num1<100){
 cout << "El valor de num1 es menor a 100" << endl;
            system("paused");
            cout <<"ingresa otro valor "<<endl;
            cin >>num1;

    }else if(num1>100){
        cout << "el valor es mayor a 100"<<endl;
    }else{
        cout << "el valor es igual a 100"<<endl;
    }
        std::cout << "Ingrese un segundo valor: "<<std::endl;
        cin >> num2;

        double media = calcula_media(num1, num2);
        cout << "La media de los dos valores es: " << media << endl;

        return 0;
}

