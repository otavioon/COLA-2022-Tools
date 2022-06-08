#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
#define ll long long

int main() {
  ll N,b,i = 0;
  cin >> N;
  std::vector<ll> A(N);
  std::vector<ll> B(N-1);
  while(cin >> b) {
    B[i] = b;
    i++;
  }
  if (N == 2) cout << 2*B[0] << endl;
  else {
    A[N-1] = B[N-2];
    for(ll j = N-2; j >= 0; j--) {
      if (j-2 >=0 && B[j-1] >= B[j-2]) A[j] = std::min(A[j+1],B[j-1]);
      else if (j-2 >=0 && B[j-1] <= B[j-2]) A[j] = A[j+1];
      else A[j] = std::min(A[j+1],B[0]);
    }
    cout << std::accumulate(A.begin(),A.end(),0) << endl;
  }
}
