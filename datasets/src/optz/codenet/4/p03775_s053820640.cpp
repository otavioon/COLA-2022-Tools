#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
  int N;
  cin >> N;
  set<ll> divisor;
  for(int i=1;i<N+1;i++){
    if(N%i==0){
      divisor.insert(i);
      ll num = N/i;
      if(divisor.count(num)){
        printl(log10(i)+1);
        return 0;
      }
    }
  }
}
