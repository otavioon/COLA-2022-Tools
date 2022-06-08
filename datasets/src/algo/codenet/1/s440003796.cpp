#include<iostream>
using namespace std;
 
int main() {  
  int c[9];
  for(int i=0;i<9;i++){
    cin>>c[i];
  }
  int a2_a=(c[3]-c[0])-(c[4]-c[1]);
  int a2_b=(c[4]-c[1])-(c[5]-c[2]);
  int a3_a=(c[6]-c[0])-(c[7]-c[1]);
  int a3_b=(c[7]-c[1])-(c[8]-c[2]);
  
  if(a2_a==0&&a2_b==0&&a3_a==0&&a3_b==0)cout<< "Yes";
  else cout<<"No";
  
}