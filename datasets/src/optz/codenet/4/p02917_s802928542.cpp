#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,memo=0,sum=0;
  cin >>n;
  for(int i=0;i<n-1;i++){
    int b;  
    cin >>b;
      if(i==n-2){sum+=b;}
    if(i==0){sum+=b;}
    else if(b<=memo){sum+=b;}
      else if(b>memo){sum+=memo;}
      memo=b;
  }

  cout <<sum<<endl;
}