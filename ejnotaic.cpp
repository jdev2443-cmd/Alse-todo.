#include<iostream>
#include<cmath>
using namespace std;

double interes_comp(double dat1, double tasi, int numa, int ans){
    return dat1 * pow(1+ tasi / numa, numa * ans);
}

int main(){
    double dat1, tasi;
    int numa, ans;

    cout<<"ingrese el valor de su ingreso "<<endl;
    cin>>dat1;

    cout<<"ingrese la tasa de interes del año de interes "<<endl;
    cin>>tasi;

    cout<<"ingrese el numero de veces en el año que se aplica el interes "<<endl;
    cin>>numa;

    cout<<"ingrese el numero de años a los que desea aplicar el interes"<<endl;
    cin>>ans;

    double final =interes_comp(dat1,tasi,numa,ans);
    double ganado = final - dat1;

    cout<<"el interes compuesto fue de "<<final<<endl;
    cout<<"el valor de ganancia fue de "<<ganado<<endl;

    
    
    return 0;
}