#include <iostream>

using namespace std;

int main(void){
    
    int c = 0;
    int tempInt;
    for(int i = 0; i < 9; i++){
        cin >> tempInt;
        c += tempInt;
    }
    if(c % 3 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
    return 0;
}
