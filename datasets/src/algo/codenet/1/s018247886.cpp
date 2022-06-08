#include<bits/stdc++.h>
using namespace std;

int main(){
int c[4][4];
  for(int i=1; i<=3; i++){
   for(int j=1; j<=3; j++){
    cin>>c[i][j]; }}
  
  int X=c[1][2]+c[2][1]+c[2][3]+c[3][2]-c[2][2];
  int Y=c[1][1]+c[2][2]+c[3][3];
  
  if(X==Y){cout<<"Yes";}
  else{cout<<"No";}
}