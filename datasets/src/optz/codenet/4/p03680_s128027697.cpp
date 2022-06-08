#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<bool> oshita(N,false);
  vector<ll> osu(1,0);
  oshita.at(0) = true;
  for ( ll i = 0; i < N; i++ ) {
    cin >> A.at(i);
    A.at(i)--;
  }
  for(ll i = 0; i < N; i++ ) {
    osu.push_back(A.at(osu.at(i)));
    if(osu.at(i+1) == 1){
      cout << i+1 <<  endl;
      break;
    }
    if(oshita.at(osu.at(i+1)) == true){
      cout << -1 << endl;
      break;
    }   
    oshita.at(osu.at(i + 1)) = true;
  }
  //cout << osu.size() << endl;
  /*for( ll i = 0; i < N; i++) {
    cout << osu.at(i) << endl;
    cout << oshita.at(i) << endl;
  }*/
}
    
  