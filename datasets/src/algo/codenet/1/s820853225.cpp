#include <iostream>
using namespace std;

int main(){
  int c[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>c[i][j];
    }
  }
  
  int a[3],b[3];
    a[0]=0;
    b[0]=c[0][0];
    a[1]=c[1][0]-b[0];
    b[1]=c[0][1]-a[0];
    a[2]=c[2][1]-b[1];
    b[2]=c[1][2]-a[1];
    if(a[2]==c[2][2]-b[2] and b[1]==c[1][1]-a[1]){
      cout<<"Yes"<<endl;
      return 0;
    }
  cout<<"No"<<endl;
}
