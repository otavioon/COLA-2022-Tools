#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k; cin>>n>>k;
  set<int> dis;
  for(int i=0; i<k; ++i){int d; cin>>d; dis.insert(d);}

  bool ok=false;
  while(!ok){
    int m=n;
    bool flg=false;
    while(m!=0){
      int x=m%10;
      if(dis.find(x)!=dis.end())flg=true;
      m/=10;
    }
    if(!flg)ok=true;
    else ++n;
  }  
  cout<<n<<endl;
}
