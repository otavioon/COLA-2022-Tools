#include <bits/stdc++.h>
using namespace std;
  

int main() {
  int a,b;
  
  cin >> a >> b;
  
  if((a==1)&&(b!=1)){
    cout << "Alice";
  }
  else if((a!=1)&&(b==1)){
    cout << "Bob";
  }
  
  else if(a>b){
    cout << "Alice";
  }
  
  else if(a<b){
    cout << "Bob";
  }
  
  else if(a==b){
    cout << "Draw";
  }
    
}
