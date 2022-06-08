#include<iostream>

using namespace std;

int main(){

  int a,b;
  cin>>a>>b;
  if(a==1 && b==1)cout<<"Draw";
  else if(a==1 && b !=1)cout<<"Alice";
  else if(b==1 && a !=1)cout<<"Bob";
  else if(a>b)cout<<"Alice";
  else if(b>a) cout<<"Bob";
  else cout<<"Draw";
  return 0;
}