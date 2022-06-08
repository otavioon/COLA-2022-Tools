#include <cstdio>
#include <algorithm>
using namespace std;
#define OKU 100000
typedef long long llong;
int N;
int A[OKU],B[OKU],C[OKU];
llong cnt=0;
int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++)scanf("%d",&A[i]);
  for(int i=0;i<N;i++)scanf("%d",&B[i]);
  for(int i=0;i<N;i++)scanf("%d",&C[i]);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        if(A[i]<B[j]&&B[j]<C[k]){cnt++;}
      }
    }
  }
  printf("%lld",cnt);
  return 0;
}
