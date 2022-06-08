#include <cstdio>
#include <iostream>
#include <algorithm>
#define M 100005
using namespace std;
int N,A[M],B[M],C[M];
int ans=0;
int a,c;
int TANSAKU_AB(int i){
  int left=0,mid,right=N;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]<B[i]) right=mid;
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
    a=TANSAKU_AB(i);
    c=TANSAKU_BC(i);
    ans+=a*c;
  }
  printf("%d\n",ans);
  return 0;
}
