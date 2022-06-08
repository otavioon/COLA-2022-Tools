#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007 // 10^9+7
#define INF 99999999999 //10^12-1
#define dev 998244353 //tenka1
#define P pair<int,int>
#define F first
#define S second
int n,k;
int x[13];
signed main(){
    cin>>n>>k;
    rep(i,k)cin>>x[i];
    while(1){
        int a=n/1000,b=(n/100)%10,c=(n/10)%10,d=n%10;
        if(n<1000)a=d;
        if(n<100)b=d;
        if(n<10)c=d;
        bool ok=true;
        rep(i,k){
            if(x[i]==a||x[i]==b||x[i]==c||x[i]==d)ok=false;
        }
        if(ok){
            cout<<n<<endl;
            return 0;
        }
        else n++;
    }
    return 0;
}

