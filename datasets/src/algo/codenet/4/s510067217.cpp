#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

#define INF 1 << 29
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

int l;
string n;
bool num[10] = {false};

bool ok(string s){
  REP(i,s.size()){
    int a = s[i]-'0';
    if(num[a]==false) return false;
  }
  return true;
}

int main(){
  cin >> n >> l;
  REP(i,10){
    num[i] = true;
  }
  REP(i,l){
    int a;
    cin >> a;
    num[a] = false;
  }
  FOR(i,stoi(n),100000){
    if(ok(to_string(i))){
      cout << i << endl;
      return 0;
    }
  }
}
