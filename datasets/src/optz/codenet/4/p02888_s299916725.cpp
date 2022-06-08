#include <iostream>
using namespace std;
int n,l[2000],num[10000],sum[10000];
long long ans=0LL;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
        num[l[i]]++;
    }for(int i=1;i<=10000;i++)sum[i]=sum[i-1]+(num[i]!=0?1:0);
    ans=0;
    for(int i=1;i<=1000;i++){
        if(num[i]==0)continue;
        num[i]--;
        for(int j=i;j<=1000;j++){
            if(num[j]==0)continue;
            int x=j-1; if(num[j]==1)x++;
            // cout<<i<<" "<<j<<" "<<ans<<endl;
            ans+=sum[i+j-1]-sum[x];
        }
    }
    cout<<ans<<endl;
    return 0;
}