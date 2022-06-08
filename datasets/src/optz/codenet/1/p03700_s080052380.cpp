#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int a,b;
bool check(vector<int>vec,long long target,int n);
int main(){
  int n;
  vector<int>vec;
  cin>>n;
  cin>>a>>b;
  for(int i;i<n;i++){
    int data;
    cin>>data;
    vec.push_back(data);
  }
  
  sort(vec.begin(),vec.end());
  int left=1;
  int right=1e9+9;
  int target=left+(right-left)/2;
  while(left+1<right){
    if(check(vec,target,n)==true){
      right=target;
    }else{
      left=target;
    }
    target=left+(right-left)/2;
  }
  
  cout<<right<<endl;
  return(0);
}

bool check(vector<int>vec,long long target,int n){
  long long c=a-b;
  long long cnt=0;
  for(int i=0;i<n;i++){
    if((long long)vec[i]-(long long)b*(long long)target>0){
      cnt+=((long long)vec[i]-(long long)b*(long long)target+c-1)/(long long)c;
    }
  }
  if(cnt<=target){
    return(true);
  }
  return(false);
}
