#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i,n) for(int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"

#define MOD 1e9+7
#define PI acos(-1.0)
#define ll long long
//---------------------------

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int x[9];
  REP(i,9) cin>>x[i];
  int d1,d2,d3,c1,c2,c3;
  d1 = x[0];
  d2 = x[1];
  d3 = x[2];
  c1 = 0;
  c2 = x[3] - d1;
  c3 = x[6] - d1;
  if(x[4]==c2+d2 && x[5]==c2+d3 && x[7]==c3+d2 && x[8]==c3+d3) {
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }

  return 0;
}
