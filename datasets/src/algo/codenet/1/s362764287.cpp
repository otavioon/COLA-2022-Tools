#include<iostream>
using namespace std;

bool moddo(int c[]){
  if(c[0] % 3 == c[1] % 3 && c[0] % 3 == c[2] % 3){
    return true;
  }
  else {
    return false;
  }
}

int main(){
  int c1, c2, c3;
  int c[3];
  for(int i=0; i<3; i++){
    cin >> c1 >> c2 >> c3;
    c[i] = c1 + c2 + c3;
  }
  if(moddo(c)){
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}
