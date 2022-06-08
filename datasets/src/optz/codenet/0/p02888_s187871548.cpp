#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()

vector<int64_t> L;
int64_t N;
int64_t count2 = 0;

void cal(int64_t a, int64_t b, int64_t c){
  if(a > -1 && b > -1 && c >-1){
    if( (L.at(a) < (L.at(b) + L.at(c)) ) &&
    (L.at(b) < (L.at(c) + L.at(a)) ) &&
    (L.at(c) < (L.at(a) + L.at(b)) )
    ){
      count2++;
      
    }
    return;
  }
  if(a < 0){
    REP(i,N){
      cal(i,-1,-1);
    }
  }else if (b < 0)  {
    FOR(i,a+1,N){
      cal(a,i,-1);
    }
  }else{
    FOR(i,b+1,N){
      cal(a,b,i);
    }
  }
 
}

int main() {
  
  

  cin >> N;
  int64_t t;
  REP(i,N){
    cin >> t;
    L.push_back(t);
  }
  cal(-1,-1,-1);
  cout << count2 << endl;
  

}