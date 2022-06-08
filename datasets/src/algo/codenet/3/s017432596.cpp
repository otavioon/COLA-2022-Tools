#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define F(i,a,n) for(int i = (a); i < (n); ++i)
#define F_minus(i,a,n) for(int i = (a); i > (n); --i)
using namespace std;
int main(){
  int N;
  cin >> N;
  long long A[N];
  long long B[N];
  long long C[N];
  int ans = 0;
  F(i,0,N){
    cin >> A[i];
  }
  F(i,0,N){
    cin >> B[i];
  }
  F(i,0,N){
    cin >> C[i];
  }
  sort(A,A+N);
  sort(B,B+N);
  sort(C,C+N);
  F(i,0,N){//A loop
    //cout << "A : " << i << endl;
    int j = 0;
    bool flag = false;
    while(A[i] >= B[j]){
      j++;
      if(j == N){
        flag = true;
      }
    }
    if(!flag){
      //cout << B[j] << endl;
      F(k,j,N){
        int l = 0;
        bool flag2 = false;
        while(B[k] >= C[l]){
          l++;
          if(l == N){
            flag2 = true;
          }
        }
        if(!flag2){
          //cout << l  << " => " <<  N -l  << endl;
          ans += N -l;
        }
      }

    }

  }

  cout << ans << endl;
  return 0;
}