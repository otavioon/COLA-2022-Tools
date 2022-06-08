#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    int n;
    cin>>n;
    int a[n];
    long long ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if( !((a[i]+a[j]) & (a[i]+a[j]-1))){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}