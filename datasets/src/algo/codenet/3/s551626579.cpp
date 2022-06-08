#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 100005
using namespace std;
int N,A[M],B[M],C[M];
int cnt=0;
int TANSAKU_AB(int i){
  int left=0,mid,right=N;
  while(left<right){
    mid=(left+right)/2;
    if(A[i]<B[mid]) right=mid;
    else left=mid+1;
  }
  return left;
}
int TANSAKU_BC(int i){
  int left=0,mid,right=N;
  while(left<right){
    mid=(left+right)/2;
    if(B[i]<C[mid]) right=mid;
    else left=mid+1;
  }
  return left;
}
int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++) scanf("%d",&A[i]);
  for(int i=0;i<N;i++) scanf("%d",&B[i]);
  for(int i=0;i<N;i++) scanf("%d",&C[i]);
  sort(A,A+N);sort(B,B+N);sort(C,C+N);
  for(int i=0;i<N;i++){
    for(int j=TANSAKU_AB(i);j<N;j++){
      for(int k=TANSAKU_BC(j);k<N;k++){
        cnt++;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
