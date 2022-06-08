#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fo(i,s,e) for( i=s;i<e;i++)
#define rfo(i,s,e) for(i=s;i>e;i--)
#define LL long long int 
const LL MOD=1e9+7;
#define pb push_back
#define pob pop_back()
#define sp " "
#define ff first
#define ss second
//            When something is important enough, you do it even if the odds are not in your favor.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // code goes here
    int t=1;//cin>>t;
    while(t--){
      LL n,i;cin>>n;
      LL a[n],b[n-1];
      fo(i,0,n-1) cin>>b[i];
      fo(i,0,n) a[i]=0;
      fo(i,1,n-1){
        a[i]=min(b[i-1],b[i]);
      }
      a[0]=max(a[1],b[0]);
      a[n-1]=max(b[n-2],a[n-2]);
      LL sum=0;
      fo(i,0,n) sum+=a[i];
      cout<<sum;
    }
    return 0;
}