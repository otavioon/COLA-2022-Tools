#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int part[3][100000];
//0=up,1=mid,2=down
int n;

int binarysearch(int terget,int key){
  int left=0;
  int right=n;
  while(left<right){
    int mid=(left+right)/2;
    if(part[key][mid]<=terget)
      left=mid+1;
    if(part[key][mid]>terget)
      right=mid;
  }
  return left;
}
int main(){
  long long ans=0;
  
  cin >> n;
  for(int i=0;i<3;i++){
    for(int j=0;j<n;j++){
      cin >> part[i][j];
    }
    sort(part[i],part[i]+n);
  }
  
  for(int i=0;i<n;i++){
      part[0][i]=binarysearch(part[0][i],1);
    for(int j=part[0][i];j<n;j++)
      ans+=n-binarysearch(part[1][j],2);
  }
  //cout << part[0][i] << endl;

  cout << ans << endl;

  return 0;
}