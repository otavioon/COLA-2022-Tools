#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    ll k,ans=0;
    cin>>k;
    ll n=s.length();
    if(n==1){
        cout << k/2<<endl;
        return 0;
    }
    bool maki=true;
    for(ll i=0;i<n;i++){
        if(i!=n-1){
            if(s[i]==s[i+1]){
                ans++;
                i++;
                if(i==n-1){
                    maki=false;
                }
            }
        }
        
    } 
    ans*=k;
    if(s[0]==s[n-1]&&maki){
        ans+=k-1;
    }
    cout << ans<<endl;
    return 0;
}
