#include <bits/stdc++.h>
using namespace std;

int main(){

int N, acnt, ccnt;
  cin >> N;
long long cnt = 0;  
int A[N], B[N], C[N];
  for(int i = 0;i < N;i++) cin >> A[i];
  for(int i = 0;i < N;i++) cin >> B[i];
  for(int i = 0;i < N;i++) cin >> C[i];
  
  sort(A, A + N);
  sort(B, B + N);
  sort(C, C + N);
  
  for(int j = 0;j < N;j++){
    acnt = 0;
    ccnt = 0;
    for(int i = 0;i < N;i++){
      if(B[j] <= A[i]){
      acnt = i;
        break;
      }
      else if(i == N - 1) acnt = N;
    }
    for(int k = 0;k < N;k++){
      if(B[j] < C[k]){
      ccnt = N - k;
        break;
      }
      else if(k == N - 1) ccnt = 0;
    }
   cnt += acnt * ccnt; 
  }

  cout << cnt << endl;
  return 0;
  
}