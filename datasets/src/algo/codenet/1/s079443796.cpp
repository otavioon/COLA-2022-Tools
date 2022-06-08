#include<iostream>
using namespace std;

int c[3][3];

int main(){

    int tmp = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> c[i][j];
            tmp+=c[i][j];
        }
    }

    if(tmp % 3){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

}