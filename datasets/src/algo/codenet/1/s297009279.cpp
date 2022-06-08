#include <iostream>
using namespace std;
int main(){
  int a,b,c;cin>>a>>b>>c;
  for(int i = 0; 2 > i; i++){
    int x,y,z; cin >> x>>y>>z;
    if(!(a-b == x-y && c-b == z-y)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}