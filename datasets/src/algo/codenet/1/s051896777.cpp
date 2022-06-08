#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<signed(n);i++)
#define EREP(i,n) for (int i=1;i<=(n);i++)
#define ALL(a) (a).begin(),(a).end()
//#define EVEL 1

#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const int MOD = 1000000007;
const ll INF = 20000000000;
struct edge {int to,cost;};
#define VMAX 50+10
//typedef std::pair<int,int> P;


    bool F=true;
    ll C[4][4];
    ll A,a;
int main(){
    ios_base::sync_with_stdio(false);
    REP(i,9){cin>>a;A+=a;}
    cout<<(A%3==0?"Yes":"No")<<endl;
    return 0;
}