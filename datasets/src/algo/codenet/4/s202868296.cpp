#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  set<int> D;
  for(int i=0;i<K;++i){
    int d;
    cin>>d;
    D.insert(d);
  }

  int n=N;
  while(true){
    set<int> S;
    int m=n;
    bool judge=true;
    while(m>0){
      if(D.count(m%10)) judge=false;
      
      m -= m%10;
      m /= 10;
    }
    
    if(judge){
      cout<<n<<endl;
      break;
      }
    
    ++n;
  }

}
