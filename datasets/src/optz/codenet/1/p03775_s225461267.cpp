#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include <queue>
#include<algorithm>
#include <limits.h>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define EREP(i,n) for (int i=1;i<=(n);i++)
const ll MOD = 1000000007;
    ll N,sum=0,ans=LONG_MAX,c;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    ll MAX=sqrt(double(N));
    EREP(i,MAX){
      if(N%i==0){
        ll A=max((ll)i,N/(ll)i);

        ans=min(ans,ll(log10(A)+1));

      }
    }
    cout<<ans;
    return 0;
}
