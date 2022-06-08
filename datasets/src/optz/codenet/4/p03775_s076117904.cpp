#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long long N;
    cin>>N;
    set<long long> div;//Nの約数を全列挙
    rep(i,(int)ceil(sqrt(N))){
        if(N%(i+1)==0){
            div.insert(i+1);
        }
    }
    int ans=10000;
    int cnt=0;
    long long bud;
    for(auto x : div){
        bud=N/x;
        cnt=max(to_string(x).size(),to_string(bud).size());
        ans=min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}