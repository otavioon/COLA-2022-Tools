

#include<bits/stdc++.h>
//macros
using namespace std;
typedef long long ll;
typedef pair<int, int > Pii;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
#define pb push_back
#define rs resize 
#define rep(i, a, b) for(int i=(a); i<(b); i++)
const long long int mod = 1e9 + 7;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define COUT(a) cout << a << endl

Vll l(2000);
int main(){
    ll N, res=0;
    cin >> N;
    l.rs(N);
    rep(i,0,N) cin >> l[i];
    rep(i,0,N){
        rep(j,i+1,N){
            rep(k,j+1,N){
                if(l[i]+l[j]-l[k]>0
                && l[i]-l[j]+l[k]>0
                && -l[i]+l[j]+l[k]>0) res++;
            }
        }
    }
    COUT(res);
}
