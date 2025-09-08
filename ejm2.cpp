#include <iostream>
int main(){
    int x=12,y=87;
    int num1,num2;
    if(x>y){
        std::cout<<"x greate than y: "<<x<<std::endl;
    }
    else if (x<y){
        std::cout<<"x less than y: "<<x<<std::endl;
    }
    else{
        std::cout<<"x less than y: "<<x<<std::endl;
    }
    std::cout<<"ingrese un valor: "<<std::endl;
    std::cin>>num1;
    //par o imparf
    if (num1%2==0){
        std::cout<<"el numero es par"<<std::endl;
    }else{
        std::cout<<"el numero es impar"<<std::endl;
    }
    std::cout<<"ingrese un valor num2: "<<std::endl;
    std::cin>>num2;
    if(num1%2==0 && num2%2==0){
        std::cout<<"los dos numeros son pares 0"<<std::endl;        
    }else if(num1%2==0 && num2%2!=0){
        std::cout<<"num1 es par y num2 es impar"<<std::endl;
    }
    else if(num1%2==1 && num2%2==0){
        std::cout<<"num1 es par"<<std::endl;
    }
}