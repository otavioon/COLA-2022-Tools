#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main(){
    int a[]={105,135,165,189,195};
    lld n,i,c=0;
    cin>>n;
    for(i=0;i<5;i++){
        if(a[i]<=n){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}