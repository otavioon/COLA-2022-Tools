#include<iostream>
#define rep(i, n) for(int i=1; i<=n; i++)
using namespace std;

int main(void){
  int sum;
  rep(i,3)  rep(j,3){
    int tmp;  cin>>tmp;
    sum+=tmp;
  }
  if(sum%3==0)  cout<<"Yes"<<endl;
  else  cout << "No" << endl;
  return 0;
}
