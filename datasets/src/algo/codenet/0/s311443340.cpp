#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main() {
    string S;
    ll N;
    cin >> S >> N;
    ll s=S.size();
    ll count=1,sum=0,count1=0,count2=0;
    bool same=true;
    bool first=true;
    rep(i,s-1){
        if (S[i]==S[i+1]){
            count++;
        }
        else {
            if (first){
                count1=count;
                first=false;
            }
            sum+=count/2;
            count=1;
        }
        if (i==s-2&&count>1){
            count2=count;
            rep(j,s-1){
                if (S[(s-1+j)%s]==S[(s+j)%s]){
                    count++;
                }
                else {
                    count/=2;
                    break;
                }
            }
        }
        else if(i==s-2){
            count/=2;
        }
        if (S[i]!=S[i+1]){
            same=false;
        }
    }
    if (same){
        cout << s*N/2 << endl;
    }
    else {
        count1/=2,count2/=2;
        sum-=count1;
        cout << count1+sum*N+count*(N-1)+count2 << endl;
    }
}
