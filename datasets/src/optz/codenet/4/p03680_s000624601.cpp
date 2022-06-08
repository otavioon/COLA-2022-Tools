#include<bits/stdc++.h>
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<int,int>
#define V vector<int>
#define S set<int>
#define pb(v) push_back(v)
V vec;
S s;
int ans = 0;
int calu(int i){
    if(i+1 == 2){
        return ans;
    }
    ans++;
    int a = s.size();
    s.insert(i+1);
    if(s.size()==a){
        return -1;
    }
    calu(vec.at(i)-1);
}
int main(){
    vec.clear();
    s.clear();
    CIN(N);
    REP(a,N){
        CIN(b);vec.pb(b);
    }
    int a = calu(0);
    COUT(a);
    return 0;
}
