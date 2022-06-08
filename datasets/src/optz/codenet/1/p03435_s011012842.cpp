#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV int(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}

/*Coding Space*/
int main(){
  int in[3][3];
  rep(i,3)rep(j,3)cin >> in[j][i];
  
  rep(a1,202)rep(a2,202)rep(a3,202){
    int b1,b2,b3;
    b1 = in[0][0] - a1;
    b2 = in[0][1] - a1;
    b3 = in[0][2] - a1;
    //cerr << b1 << b2 << b3 << endl;
    if(
      a2 + b1 == in[1][0] &&
      a3 + b1 == in[2][0] &&
      a2 + b2 == in[1][1] &&
      a3 + b2 == in[2][1] &&
      a2 + b3 == in[1][2] &&
      a3 + b3 == in[2][2]
    ){
        cout <<"Yes" << endl;
        return 0;
    }
  }
  cout << "No" << endl;
}