#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin>>S;
  int N,length;
  cin>>N;
  length=S.size();
  int A[100]={0};
  for(int i=0;i<length;i++){
    if(i==0){
      if(S[0]==S[1])A[0]+=1;
      if(S[0]==S[length-1])A[0]+=1;
    }
    else if(i==length-1){
      if(S[length-1]==S[1])A[length-1]+=1;
      if(S[length-1]==S[length-2])A[length-1]+-1;
    }
    else{
      if(S[i]==S[i-1])A[i]+=1;
      if(S[i]==S[i+1])A[i]+=1;
    }
  }
  int count=0;
  for(int i=0;i<length;i++){
    if(A[i]==2){
      A[i]=0;
      count+=1;
      if(i==0){
        A[length-1]-=1;
        A[1]-=1;
      }
      else if(i==length-1){
        A[i-1]-=1;
        A[0]-=1;
      }
      else{
        A[i-1]-=1;
        A[i+1]-=1;
      }
    }
  }
  for(int i=0;i<length;i++){
    if(A[i]==1){
      A[i]=0;
      count+=1;
      if(i==0){
        A[length-1]=0;
        A[1]=0;
      }
      else if(i==length-1){
        A[0]=0;
        A[i-1]=0;
      }
      else{
        A[i-1]=0;
        A[i+1]=0;
      }
    }
  }
  cout<<count*N<<endl;
}