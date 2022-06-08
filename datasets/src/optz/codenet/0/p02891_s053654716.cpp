#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
#define maxs(a,b) a=max(a,b);
#define mins(a,b) a=min(a,b);
#define max3(a,b,c) max(a,max(b,c)) 
#define mix3(a,b,c) mix(a,mix(b,c))
#define pairi pair<int,int>

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;

int main(){
   
    string s;
    ll k;
    cin>>s>>k;

    ll ans=0;
    int a=0,b=s.size()-1;
    if(s[a]==s[b]){
        while(s[a]==s[a+1]){
            a++;
            if(a==b){
                cout<<s.size()*k/2<<endl;
                return 0;
            }
        }
        while(s[b]==s[b-1])b--;
        int n=a+1 + s.size()-1-b;
        ans+=(n/2)*k;
        if(n%2==0 && a%2==1)ans--;
        a++;
        b--;
    }
    
    int c=1,sans=0;
    repa(i,a,b+1){
        if(s[i]==s[i+1])c++;
        else{
            sans+=c/2;
            c=1;
        }
    }    

    ans+=sans*k;

    cout << ans << endl;
    
    return 0;
}