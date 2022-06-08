#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
const ll mod=1000000007;
ll gcd(ll a,ll b){if(a<b)swap(a,b);while((a%b)!=0){a=b;b=a%b;}return b;}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

set<int> s;
bool chek(int n){
  while(n>0){
    int k=n%10;
    if(s.count(k)) return 0;
    else n/=10;
  }
  return 1;
}

int main(){
  int n,k; cin>>n>>k;
  rep(i,k){
    int d; cin>>d;
    s.insert(d);
  }

  while(1){
    if(chek(n)){
      cout<<n<<endl;
      return 0;
    }else n++;
  }

  return 0;
}
