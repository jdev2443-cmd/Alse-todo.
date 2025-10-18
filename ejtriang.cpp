#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numRows;
    cout << "ingrese el numero de filas del triangulo de pascal: ";
    cin >> numRows;

    vector<vector<int>> pasc(numRows);

    for(int i =0; i < numRows; i ++) {
        pasc[i].resize (i +1);
        pasc[i][0]= pasc[i][i] = 1;

        for (int j = 1; j < i; j++){
            pasc[i][j] = pasc[i - 1][j - 1] + pasc[i - 1][j];
        }

    }
    cout << "\nTriangulo de pascal\n";
    for (const auto & fila :pasc){
        for (int num : fila)
        cout << num << " ";
    cout << endl;

    }
    return 0;
    
}
