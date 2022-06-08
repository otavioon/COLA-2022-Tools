#include<iostream>
#include<vector>
using namespace std;
int main(){
  int i,d[9],a[3],b[3];
  for(i=0;i<9;i++){
    cin>>d[i];
  }
  b[0]=0;
  a[0]=d[0];
  for(i=1;i<3;i++){
    b[i]=d[i]-a[0];
    a[i]=d[i*3]-b[0];
  }

  //check
  for(i=0;i<9;i++){
    if(d[i]!=(a[i/3]+b[i%3])){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
	return 0;
}