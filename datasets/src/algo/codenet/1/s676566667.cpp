#include<bits/stdc++.h>
using namespace std;

int a[3][3];

int main(){

    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cin>>a[i][j];
        }
    }

    bool f=1;
    int d1=abs(a[0][0]-a[1][0]), d2=abs(a[1][0]-a[2][0]);
    for(int i=1; i<3; ++i){
        if( abs(a[0][i]-a[1][i])!=d1||abs(a[1][i]-a[2][i])!=d2 ){
            f=0;
            break;
        }
    }

    if(f)
        puts("Yes");
    else
        puts("No");


    return 0;
}
