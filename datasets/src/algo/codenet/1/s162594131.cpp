#include<iostream>

using namespace std;

int main(){
    int c[3][3];
    for(int i=0;i<3;i++)cin >> c[i][0] >> c[i][1] >> c[i][2];

    int diff[2];
    diff[0] = c[0][0] - c[0][1];
    diff[1] = c[0][1] - c[0][2];
    for(int i=1;i<3;i++){
        if(c[i][0]-c[i][1]!=diff[0]){
            cout << "No" << endl;
            return 0;
        }
        if(c[i][1]-c[i][2]!=diff[1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
