#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  uint64_t A[N],B[N],C[N];
  uint64_t numA=0,numB=0;
  uint64_t ans=0,sumB[N];
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  for(int i=0; i<N; i++) cin >> C[i];
  for(int i=0; i<N; i++) sumB[i] = 0;
  sort(A,A+N);
  sort(B,B+N);
  sort(C,C+N);
  for(int i=0; i<N; i++){
    while(C[i]>B[numB] && numB<N){
      if(numB!=0) sumB[numB] = sumB[numB-1];
      while(B[numB]>A[numA] && numA<N){
        numA++;
      }
      sumB[numB] += numA;
      numB++;
    }
    if(numB!=0) ans += sumB[numB-1];
  }
  cout << ans<< endl;
  return 0;
}
