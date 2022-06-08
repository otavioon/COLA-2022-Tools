#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int a[3],b[3],c[3];
    for(int i=0;i<3;i++){
        cin>>c[0]>>c[1]>>c[2];
        a[i]=c[0]-c[1];
        b[i]=c[1]-c[2];
    }
    if(a[0]==a[1]&&a[1]==a[2]&&b[0]==b[1]&&b[1]==b[2]){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}
