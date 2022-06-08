#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >>N ;
  vector<string> s(101),t(101);
  vector<int> moneyv(N);
  for(int i=0;i<N;i++){cin>>s.at(i);}
  cin>>M;
  for(int i=0;i<M;i++){cin>>t.at(i);}
  for(int i=0;i<N;i++){
    int money=0;
    for(int j=0;j<N;j++){
      if(s.at(i)==s.at(j)){money++;}
    }
      for(int k=0;k<M;k++){
        if(s.at(i)==t.at(k)){money--;}
      }
      if(money<0){money=0;}
      moneyv.at(i)=money;
    
  }
  int ans=0;
  for(int i=0;i<N;i++){
      bool flag=true;
    for(int j=0;j<N;j++){
      if(moneyv.at(i)<moneyv.at(j)){flag=false;}
    }
    if(flag){ans=moneyv.at(i);}
  }
  cout<<ans<<endl;
//  for (int i = 0; i < moneyv.size(); i++) {
//    cout << moneyv.at(i) << endl;
//  }
}
