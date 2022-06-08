#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[100],ans=0;
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(i==0) ans+=b[0];
        else if(i==n-1) ans+=b[n-2];
        else ans+=min(b[i],b[i-1]);
    }
    cout<<ans;
}