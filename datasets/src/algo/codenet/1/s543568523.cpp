#include <iostream>

using namespace std;

int main(){
    int sum=0;
    for(int i=0; i<9; ++i){
        int c;
        cin >> c;
        sum+=c;
    }
    cout << (sum % 3 == 0 ? "Yes" : "No") << endl;
    return 0;
}
