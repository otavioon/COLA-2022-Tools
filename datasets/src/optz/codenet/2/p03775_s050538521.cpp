#include <bits/stdc++.h>
using namespace std;
int main(){
  long N;
  cin >> N;
  
  vector<int> n(1,1);
  for(long i=2; i<=N/i; i++){
    if(N%i!=0) continue;
    N/=i;
    n.push_back(i);
    i--;
  }
  n.push_back(N);
  int end=n.size(), ans=11;
  long a=1;
  for(int i=0; i<end; i++){
    if(i%2==0){
      a*=n.at(i/2);
      n.at(i/2)=1;
    }
    else{
      a*=n.at(end-1-i/2);
      n.at(end-1-i/2)=1;
    }
    long b=1;
    for(int j=0; j<end; j++){
      b*=n.at(j);
    }
    long x=a, y=b;
    int fx=1, fy=1;
    for(int k=0; k<fx; k++){
      x/=10;
      if(x==0) break;
      fx++;
    }
    for(int k=0; k<fy; k++){
      y/=10;
      if(y==0) break;
      fy++;
    } 
    int fz=max(fx,fy);
    ans=min(ans,fz);
  }
  cout << ans << endl;
}