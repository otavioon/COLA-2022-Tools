#include <iostream>
using namespace std;


int c[7][7];
int a[5];
int b[5];

int main(){
    for(int i =1;i < 4;i++){
        for(int j = 1;j < 4;j++){
            cin >> c[i][j];
        }
    }

    //c[1][1] = a[1] + b[1];
    //c[2][1] = a[2] + b[1];
    //c[1][2] = a[1] + b[2];
    //c[2][2] = a[2] + b[2];

    if(c[2][2] != c[2][1] + c[1][2] - c[1][1]){
        cout << "No" << endl;
        exit(0);
    }
    if(c[2][2] != c[2][1] + c[3][2] - c[3][1]){
        cout << "No" << endl;
        exit(0);
    }
    if(c[2][2] != c[1][2] + c[2][3] - c[1][3]){
        cout << "No" << endl;
        exit(0);
    }
    if(c[2][2] != c[2][3] + c[3][2] - c[3][3]){
        cout << "No" << endl;
        exit(0); 
    }

    cout << "Yes" << endl;

}