#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

#define INF 1 << 30
#define REP(i,n) for(ll i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(ll i=(k);i<(int)(n);i++)



vector<bool> gen_sosuu(vector<bool> sosuu){
  int size = sosuu.size();
  REP(i,size){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(size)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<size;j++){
      sosuu[i*j] =false;
    }
  }
  return sosuu;
}

ll n;

int main(){
  cin >> n;
  if(n%2==0) cout << n <<endl;
  else cout << 2*n <<endl;
}
