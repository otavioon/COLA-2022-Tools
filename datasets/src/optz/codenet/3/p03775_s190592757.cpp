#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>


#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define lint long long

const int INF = 1e9;
const int MOD = 1e9+7;
const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで


using namespace std;
int a,b,c,d;
vector<lint> ret;
lint n;
int main(){
  cin >> n;
  for(lint i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  if(ret.size()%2==1){
    int k = ret[ret.size()/2];
    cout << to_string(k).size() << endl;
    return 0;
  }
  else{
    int k = ret[ret.size()/2];
    cout << to_string(k).size() << endl;
    return 0;
  }
  return 0;
}
