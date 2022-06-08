#include <bits/stdc++.h>
using namespace std;

int main(){
  int num[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>num[i][j];
      if(i!=0){
        num[i][j]-=num[0][j];
      }
    }
  }
  if(num[1][0]==num[1][1] && num[1][1]==num[1][2] && num[2][0]==num[2][1] && num[2][1]==num[2][2]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}