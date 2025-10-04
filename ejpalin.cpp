#include <iostream>
using namespace std;

bool palindromo(int x){
    if (x < 0) return false;
    int ori =x;
    long reve = 0;
    
    while(x != 0){
        int digi = x % 10;
        reve = reve * 10 + digi;
        x /= 10;
    }
    return ori == reve;

}
int main(){
    int x;
    cout<< "ingrese un numero ";
    cin >> x;
    if (palindromo(x)){
        cout<< x << "es un numero palindromo "<<endl;
    }
    else{
        cout<<x<<"no es un numero palindromo "<<endl;

    }
    return 0;

}