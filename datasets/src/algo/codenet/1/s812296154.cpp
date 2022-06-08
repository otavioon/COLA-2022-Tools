#include <iostream>

using namespace std;

int a[3][3];

int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=2;i++){
        int b = a[i][0] - a[0][0];
        for(int j=1;j<=2;j++){
            if(b != a[i][j] - a[0][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}