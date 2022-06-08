
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<int, int> pint;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

Int judge(Int cut, vector<Int> logs){
    Int ans=0;
    for(int i=0; i<logs.size(); i++){
        Int l=logs[i];
        while(l>cut){
            l-=cut;
            ans++;
        }
       
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int n,k; cin>>n>>k;
    vector<Int> a(n,0);
    rep(i,n) cin>>a[i];
    Int ok=1000000100;
    Int ng=-1;
while(abs(ok-ng)>1){
        Int mid=(ok+ng)/2;
        if(judge(mid,a)<=k){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    cout<<ok<<endl;
    return 0;
}