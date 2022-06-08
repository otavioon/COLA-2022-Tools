
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
typedef double db;
const db pi=3.1415926535898;
char a[105];
ll k;
int main(){
    std::ios::sync_with_stdio(false);
    cin>>a;
    cin>>k;
    ll f=1;
    char c=a[0];
    ll len=strlen(a);
    for(ll i=0;i<len;i++){
        if(a[i]!=c){
            f=0;
            break;
        }
    }
    if(f){
        cout<<(len*k)/2<<endl;
    }
    else{
        ll p1,p2;
        //cout<<len<<endl;
        if(a[0]==a[len-1]){
            c=a[0];
            for(ll i=0;i<len;i++){
                if(a[i]!=c){
                    p1=i;
                    break;
                }
            }
            for(ll i=len-1;i>=0;i--){
                if(a[i]!=c){
                    p2=i;
                    break;
                }
            }
        }
        else{
            p1=0,p2=len-1;
        }
        ll s1=0;
        char cc=0;
        ll tnum=0;
        //cout<<a<<endl;
        for(ll i=p1;i<=p2;i++){
            //cout<<c<<' '<<a[i]<<' '<<tnum<<endl;
            if(cc!=a[i]){
                cc=a[i];
                s1+=(tnum/2);
                tnum=1;
            }
            else{
                tnum++;
            }
        }
        s1+=tnum/2;
        //cout<<s1<<endl;
        //cout<<p1<<' '<<p2<<endl;
        cout<<s1*k+((p1)/2)+((len-p2-1)/2)+(p1+len-p2-1)/2*(k-1)<<endl;
    }
    return 0;
}

