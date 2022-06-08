#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char c[3][3];

int main(){
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            char a;
            cin>>a;
            c[i][j]=a;
        }
    }
    if(c[0][0]==c[1][2]&&c[0][1]==c[1][1]&&c[0][2]==c[1][0]){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}

