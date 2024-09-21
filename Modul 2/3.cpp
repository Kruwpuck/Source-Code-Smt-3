#include <iostream>
using namespace std;
int main(){
    float bil, rata=0, i,total=0;
    cin >> bil;
    while (bil != -999){
        total+=bil;
        i++;
        cin >> bil;
    }
    rata = total / i;
    if (total == 0){
        cout << "0";
    }else{
        cout << rata;
    }
}
