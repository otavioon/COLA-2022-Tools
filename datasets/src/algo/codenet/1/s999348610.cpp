#include <iostream>
using namespace std;
int main(){
  int n,a,b,c,d[2];
  cin >> a >> b >> c;
  d[0]=b-a;d[1]=c-a;
  for(int i=1;i<3;i++){
    cin >> a >> b >> c;
    if(d[0]!=b-a || d[1]!=c-a){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}