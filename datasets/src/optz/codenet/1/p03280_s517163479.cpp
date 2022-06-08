#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  
  int ans=0;
  int count;
  for(int i=1;i<N+1;i+=2){
    for(int j=1;j<i+1;j++){
      count=0;
      if(i%j==0)
        count++;
    }
    if(count==8)
        ans++;
  }
  cout<<ans<<endl;
}
 
  
