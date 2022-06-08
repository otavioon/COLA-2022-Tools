#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>

using namespace std;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep2(i, begin_i, end_i) for (int i = (int)begin_i; i < (int)end_i; i++)

long long INF = 1LL<<60;
long long dp[100010];
int h[100010];
int a[100010];
int b[100010];
int c[100010];
long long ans=0;
int pro_a=0,pro_c=0;
int main(){
    int n = 0;
    cin>>n;
    rep2(i,1,n+1)scanf("%d",&a[i]);
    rep2(i,1,n+1)scanf("%d",&b[i]);
    rep2(i,1,n+1)scanf("%d",&c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);


    pro_c = 1;
    rep2(i,1,n+1){
        while(pro_a<n&&a[pro_a+1]<b[i])pro_a++;
        while(pro_c<=n&&c[pro_c]<=b[i])pro_c++;
        ans += pro_a * (long long)(n-pro_c+1);
    }
    printf("%lld\n",ans);
    return 0;
}


