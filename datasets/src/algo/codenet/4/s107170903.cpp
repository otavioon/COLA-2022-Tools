#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pb push_back
const int MAXN = 1e6+7;
set<int> S;
int main(){
    fastio;
    int val,k; cin>>val>>k;
    while(k--){
        int d; cin>>d;
        S.insert(d);
    }
    for(int i=val; i<=MAXN; i++){//se ela pagar i ?
        int j = i;
        bool ok = true;
        while(j>0){
            int di = j%10;
            if(S.find(di) != S.end())ok=false;
            j = j/10;
        }
        if(ok){cout<<i<<endl; return 0;}
    }
}