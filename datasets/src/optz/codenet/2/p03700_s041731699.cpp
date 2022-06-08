#include <bits/stdc++.h>
using namespace std;

int N,A,B;
bool check(int n,vector<long long> h){
  long long zentai = (long long)B*n;
  vector<long long> nokori;
  for(int i=0;i<N;i++){
    h[i] -= zentai;
    if(h[i] > 0)
      nokori.push_back(h[i]);
  }
  if(nokori.size() == 0)return true;
  long long cnt = 0;
  for(int i=0;i<nokori.size();i++){
    cnt += (long long)ceil(1. * nokori[i] / (A-B));
  }
  if(cnt <= n)return true;
  return false;
}

int main(void) {
  cin >> N >> A >> B;
  vector<long long> h(N);
  for(int i=0;i<N;i++){
    cin >> h[i];
  }

  // 一番大きいのにAを打つ
  int low=0,hi=1e9,mid=0;
  while(hi > low+1) {
    mid = (low + hi)/2;
    if(check(mid,h)) {
      hi = mid;
    } else {
      low = mid;
    }
  }
  cout << low+1 << endl;

  return 0;
}