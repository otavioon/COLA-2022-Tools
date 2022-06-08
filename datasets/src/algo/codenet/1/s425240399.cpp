#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[9];
    for(int i=0;i<9;i++){
        cin>>a[i];
    }
    
    if(a[0]+a[4]==a[1]+a[3] && a[1]+a[5]==a[2]+a[4] && a[3]+a[7]==a[4]+a[6] && a[4]+a[8]== a[5]+a[7])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
}
