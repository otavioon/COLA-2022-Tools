#include<iostream>
using namespace std;

int c[3][3];

int main(){

    int tmp = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> c[i][j];
            //cout << c[i][j];
            tmp+=c[i][j];
        }
    }
    //cout << tmp << endl;
    int tmp2 = tmp % 3;
    //cout << tmp2 << endl;
    if(tmp2!=0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;

}