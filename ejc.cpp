#include <iostream>
#define DEBUG
// using namespace std
long double largeDecimal= 0x14525795122458781; //0b1100110
int main(){
	int height=1.8;
	char character='H';
	bool opened=false;
	unsigned int count=0;
	short score=0;
	int x, y;
	int aux;
	std::cout<<"Escriba dos numeros\n";
	std::cin >> x >> y;
	aux=x;
	x=y;
	y=aux;
	std::cout <<"X: "<< x <<"Y:"<< y << std::endl;
	return 0;

}