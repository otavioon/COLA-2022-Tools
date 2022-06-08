#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<sstream>
#include<string>
#include<utility>
#include<vector>

#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 1000000000+7
using namespace std;
typedef long long ll;

int main(){
  int N, K; cin >> N >> K;
  bool allOK = true;
  string sN = to_string(N), s = "";
  set<int> hate;
  int mini = 10, ans = -1;
  rep(i, 0, K)  {
    int n;  cin >> n;
    hate.insert(n);
  }
  for(char n:sN){
    if(hate.find(n-'0') != hate.end()){
      allOK = false;
      break;
    }
  }
  rep(i, 0, 10){
    if(hate.find(i) == hate.end()){
      mini = min(mini, i);
      if(i != 0){
        s = s+to_string(i);
        break;
      }
    }
  }
  ans = stoi(s);
  while(ans < N){
    s = s + to_string(mini);
    ans = stoi(s);
  }

  cout << (allOK?sN:s) << endl;
  return 0;
}