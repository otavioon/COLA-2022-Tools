#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    int n;
    ll a,b;
    cin >> n >> a >> b;
    ll h[n];
    rep(i,n){
        cin >> h[i];
    }

    ll l = 0;
    ll r =  922337203685477580;

    while(r-l>1){
        ll mid = (l+r)/2;
        ll count = 0;
        rep(i,n){
            if(mid*b<h[i]){
                if(a-b==1){
                    count += h[i] - mid*b;
                }else{
                    count += (h[i]-mid*b)/(a-b);
                    if((h[i]-mid*b)%(a-b)>0)count++;
                }
            }
        }
        if(count<=mid){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << r << endl;


    return 0;
}

