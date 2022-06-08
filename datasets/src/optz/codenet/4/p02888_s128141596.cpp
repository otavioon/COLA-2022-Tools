#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    int n; cin>>n;
    ll ans =0;
    vector<int>l(n);
    rep(i,n)cin>>l[i];
    sort(l.begin(),l.end());
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int a=lower_bound(l.begin(),l.end(),l[i]+l[j])-l.begin();
            ans+=a-(j+1);
        }
    }
    cout<<ans<<endl;
    }
