//                          VIVEK UPADHYAY
//                         MANIT, BHOPAL(M.P)
/**********************************************************************************************/
/**********************************************************************************************/
//                        $$ JAB-TAK TODEGA NHI,
//                           TAB -TAK CHODEGA NHI :D
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<set>
#include<unordered_map>
#include<cstdio>
#include<map>
#include<numeric>
using namespace std;
#define F first
#define S second
#define mk(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define LINE cout<<"\n" ;
#define ok cout<<"ok\n" ;
#define dbg(x) cout<<#x<<" = "<<(x)<<"\n";
typedef long long ll;
const int MAXN = 500510;
const int MAX = 1e7 + 1 ;
double pi = 3.1415926535897932384626433832795;
const ll inf=1e18 ;
ll mod = 500500507;
ll powr(ll a , ll b){ if(b==0) return 1LL ; ll x = powr(a,b/2) ; x = (x*x)%mod ; if(b%2) return ((a%mod)*x)%mod ; return x ;}
ll gcd(ll a , ll b){if(a==0) return b ; return gcd(b%a,a);}
int main () {
    
    int N ;
    cin >> N ;
    ll a[N] ;
    multiset<ll> ms ;
    for(int i = 0; i < N ;i++){
        cin >> a[i] ;
        ms.insert(a[i]) ;
    }
    int cnt=0;
   
    while(ms.empty()==false){
        ll x = *ms.rbegin() ,pw = 1LL ;
        ms.erase(ms.find(x)) ;
        while(pw <= x)
            pw*=2 ;
        auto it = ms.find(pw - x) ;
        if(it==ms.end()) continue ;
        ms.erase(it) ;
        ++cnt ;
    }
    cout<<cnt<<endl;
    return 0 ;
}
