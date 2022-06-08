#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

set<int> st;
bool ch(int x){
  bool flag = true;
  while(x>0){
    int tmp = x%10;
    if(st.find(tmp)!=st.end()){flag=false; break;}
    x/=10;
  }
  return flag;
}

int main(){
  int n,k;
  cin >> n >> k;
  rep(i,n){
    int a;
    cin>>a;
    st.insert(a);
  }
  for(; ; n++){
    if(ch(n)){break;}
  }  
  cout << n << endl;
  return 0;
}
