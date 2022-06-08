#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int ll;
int main(){
  ll c[3][3];
  for(ll i=0;i<3;i++){
    for(ll j=0;j<3;j++){
      cin >>c[i][j];
    }
  }
  ll y=c[0][0]+c[1][1]+c[2][2];
  if(c[0][0]+c[2][2]==c[0][2]+c[2][0]){
    if(c[0][1]+c[1][0]+c[2][2]==y){
      if(c[0][0]+c[1][2]+c[2][1]==y){
        cout <<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout <<"No"<<endl;
}
