#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int b[n],a[n+1];
    
    for(int i=0;i<n;i++)cin>>b[i];
    int ans=b[n-2];
    a[n-1]=b[n-2];
    for(int i=n-2;i>0;i--){
        if(b[i]>b[i-1])a[i]=b[i-1];
        else a[i]=a[i+1];
        ans+=a[i];
    }
    ans+=b[0];
    cout<<ans<<endl;
    return 0;
}