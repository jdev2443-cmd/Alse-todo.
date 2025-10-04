#include <iostream>
#include <vector> //aclaracion de un vector
#include <unordered_map> //uso de un mapa vectorial con fines de movilidad
using namespace std;

vector<int> suma(vector<int>& nums, int tar){
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++){
        int agregado = tar - nums[i];
        if (map.find(agregado) !=map.end()){
            return{map[agregado], i};
        }
        map[nums[i]] = i;
    }

    return{};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int tar = 9;

    vector<int> result = suma(nums, tar);
    cout<<"los datos dan como resultado en suma "<< tar << "son";
    for (int ind : result){
        cout<< ind << " ";
    }
    cout<<endl;
    return 0;
}