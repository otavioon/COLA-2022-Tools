#include<bits/stdc++.h>
using namespace std;
int dfs(int t,int last);
int upper(int i,int k);
int n;
int a[9][100009];
int dp[9][100009];

int main(){
  cin>>n;
  for(int i=0;i<3;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
    sort(a[i],a[i]+n);
  }
  for(int i=0;i<=n;i++)dp[0][i]=1;
  for(int i=0;i<3;i++){
    for(int j=0;j<n;j++){
      int idx=upper(i-1,a[i][j]);
      dp[i+1][j+1]=dp[i+1][j]+dp[i][idx];
    }
  }
  cout<<dp[3][n]<<endl;
  return(0);
}

int upper(int i,int k){
  if(i<0)return 0;
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[i][mid]>=k){
      right=mid;
    }
    else{
      left=mid;
    }
  }
  return right;
}
