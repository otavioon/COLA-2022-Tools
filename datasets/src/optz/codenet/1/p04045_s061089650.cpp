#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[10],ans=LLONG_MAX;
void brute(ll sum){
    //cout<<sum<<endl;
    if(sum>=n){
        ans=min(ans,sum);
        return;
    }
    if(sum==0){
        for(ll i=1;i<10;i++)if(a[i])brute(i);
    }
    else{
        for(ll i=0;i<10;i++)if(a[i])brute(sum*10 + i);
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(ll i=0;i<10;i++)a[i]=1;
    for(ll i=0,x;i<k;i++)cin>>x,a[x]=0;
    brute(0);
    cout<<ans;
}


