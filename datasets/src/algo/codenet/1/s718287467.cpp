#include<bits/stdc++.h>
using namespace std;
int main(){
    int c[3][3];
    int sum=0;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        cin >> c[i][j];
        sum += c[i][j];
    }
    if(sum==3*(c[0][0]+c[1][1]+c[2][2]))cout << "Yes" << endl;
    else cout << "No" << endl;
}