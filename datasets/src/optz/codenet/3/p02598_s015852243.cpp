#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>

#define ff first
#define ss second

using namespace std;
using pii=pair<int,int>;
using ll=long long;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    ll maxa=*max_element(a.begin(),a.end());
    ll lo=0,hi=maxa+1;

    while(lo<hi){
        ll mid=(lo+hi)/2;
        ll m=maxa-mid;
        ll cnt=0;
        for(int i=0; i<n; i++){
            cnt+=(a[i]*10)/(m*10+5);
            if((a[i]*10)%(m*10+5)==0) cnt-=1;
        }
        if(cnt<=k) lo=mid+1;
        else hi=mid;
    }
    cout<<maxa-lo+1;

    return 0;
}
