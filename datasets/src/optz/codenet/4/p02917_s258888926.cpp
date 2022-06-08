#define _GLIBCXX_DEBUG

#include "iostream"
#include "vector"
#include "numeric"

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())

#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9+7:合同式の法
 
int main(){
    
    ll n;
    cin >> n;

    vector<ll> b;
    REP(i,n-1){
        ll tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    b.push_back(b[n-2]);
    //cout << b[n-1] << endl;

    
    ll total=0;//b[n-1];
    vector<ll> a;
    a.push_back(b[0]);
    for(ll i=n-2; i>=0; i--){
        ll MIN = min(b[i],b[i+1]);
        a.push_back(MIN);
        //total += MIN;
        //cout << total << endl;
    }
    total = accumulate(a.begin(),a.end(),0);
    cout << total << endl;
    
    return 0;

}