#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char s[105];

int main(){
    ll k;
    scanf("%s",s+1);
    scanf("%lld",&k);
    ll n=strlen(s+1); bool f=0,flag=0;
    ll ss=0,fi=0,now=1,res=0,ans=0;
    for(ll i=2;i<=n;i++){
        if(s[i]==s[i-1]) now++;
        else{
            if(!fi) fi=now;
            res+=now/2;
            now=1;
        }
    }
    if(!fi) fi=now,flag=1;
    if(fi%2==1&&now%2==1&&s[n]==s[1]) f=1;
    res+=now/2;
    ans=res*k;

    ll sum;
    if(flag){
        sum=1;
    }else{
        sum=2;
    }
    if(f) ans+=k/2*sum;
    cout<<ans<<endl;
}
/*
aaaba
3

aaa
5
*/
