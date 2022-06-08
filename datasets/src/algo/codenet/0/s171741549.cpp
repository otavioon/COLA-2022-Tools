#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define fr(x,i,n) for(int x = i; x < n; ++x)
#define fb(x,i,n) for(int x = i; x >= n; --x)
#define pr pair<int,int>
#define ll long long int
const int mod=1e9+7;
/*    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nduration="<<duration.count()/1e6 << endl;
*/
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    ll ans=0;
    int i0=0,j0=n-1;
    while(i0<n&&s[i0]==s[0])
    i0++;// first element not equal to s[0]
    while(j0>i0&&s[j0]==s[0]){
        j0--; // last element not equal to s[0]
    }
    fr(i,i0,j0+1){
        int j=i;
        while(j<=j0&&s[i]==s[j])
        j++;
        ans+=(j-i)/2;
        i=j-1;
    }
    ll k;
    cin>>k;
    ans*=k;
    ll x=i0+(n-1-j0);
    ans+=(k-1)*(x/2);
    ans+=i0/2;
    ans+=(n-1-j0)/2;
    cout<<ans;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    while(t--)
    solve();

}
