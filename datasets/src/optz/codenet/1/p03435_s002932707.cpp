#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a[3][3],x[3],y[3];
    bool ok = true;
    x[0] = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < 3;i++)y[i] = a[0][i] - x[0];
    for(int i = 0;i < 3;i++)x[i] = a[i][0] - y[0];
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(x[i] + y[j] != a[i][j])ok = false;
        }
    }
    if(ok == true)cout << "Yes";
    else cout << "No";
}
