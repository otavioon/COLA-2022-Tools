#include<bits/stdc++.h>
#define ll          long long int
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         1000000000000000000
#define MAXN        200000005
#define mod         1000000007
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll k,i,n,count=0,ans=0,x,y,ans1=0;
    cin>>k;
    if(s.size()==1){
        ans=k/2;
        cout<<ans;
    }
    else{
        n=s.size();
        i=1;
        count=0;
        vector<ll> vi;
        while(i<n){
            while(i<n && s[i-1]==s[i]){
                count++;
                i++;
            }
            i++;
            vi.pb(count+1);
            count=0;
        }
        if(s[n-2]!=s[n-1]){
            vi.pb(1);
        }
        // for(auto x:vi){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        if(s[0]!=s[n-1] || k==1){
            for(auto x:vi){
                ans+=x/2;
            }
            ans=ans*1ll*k;
            cout<<ans;
        }
        else{
            x=vi.size();
            if(x==1){
                ans=(vi[0]*1ll*k);
                ans=ans/2;
                cout<<ans;
            }
            else{
                y=vi[x-1]+vi[0];
                ll z=vi[x-1];
                vi.pop_back();
                vi.pb(y);
                for(i=1;i<x-1;i++){
                    vi.pb(vi[i]);
                }
                vi.pb(z);
                // for(auto x:vi){
                //     cout<<x<<" ";
                // }
                // cout<<endl;
                k=k-2;
                for(auto x:vi){
                    ans+=x/2;
                }
                y=vi.size();
                for(i=x-1;i<y-1;i++){
                    ans1+=vi[i]/2;
                }
                ans1=ans1*1ll*k;
                ans+=ans1;
                cout<<ans;
            }
        }
    }
}