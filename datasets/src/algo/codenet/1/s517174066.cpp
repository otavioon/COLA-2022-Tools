#include <iostream>
using namespace std;
int main(){
  int k[5][5],sum=0;
  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j){
      cin>>k[i][j];
      sum+=k[i][j];
    }
  }
  if(sum%3==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}