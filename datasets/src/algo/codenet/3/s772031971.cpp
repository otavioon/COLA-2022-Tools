#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  int A[100000], B[100000], C[100000];
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  for(int i=0; i<N; i++) cin >> C[i];
  sort(A,A+N);
  sort(B,B+N);
  sort(C,C+N);
  long long AB[100000];
  int j=0;
  for(int i=0; i<N; i++){
    while(j<N&&A[j]<B[i]){
      j++;
    }
    AB[i]=j;
  }
  for(int i=1; i<N; i++){
    AB[i]+=AB[i-1];
  }
  j=0;
  long long result=0;
  for(int i=0; i<N; i++){
    while(j<N&&B[j]<C[i]){
      j++;
    }
    if(j!=0){
      result+=AB[j-1];
    }
  }
  cout << result << endl;
}