#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

int roop(int *A, int i);
using namespace std;
vector<int> v;

int main(){

  int A[100000],n,N; cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  n = roop(A,0);
  if(n < 0) cout <<  -1 << '\n';
  else cout << n << '\n';
  //for(auto itr = v.begin(); itr != v.end(); ++itr) cout << *itr << '\n';
//  auto result = find(v.begin(), v.end(), A[1]);
  //cout <<"result"<< *(v.end()) << endl;
  return 0;
}

int roop(int *A,int i){
  if(A[i] == 2) return 1;
  else if(auto x = find(v.begin(),v.end(),A[i]) != v.end()) return -100;
    //else if(i+1 == A[A[i]-1]) return -1;
  else{
    v.push_back(A[i]);
    return 1 + roop(A,A[i]-1);
  }
}
