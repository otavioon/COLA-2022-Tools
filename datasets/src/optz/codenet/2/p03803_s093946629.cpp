#include<bits/stdc++.h>
using namespace std;

int main() {
   int a,b;
   cin >> a >> b;
   if(a != 1 && b != 1){
      cout<< ((a==b) ? "Draw" : (a>b) ? "Alice" : "Bob"); 
   }else{
      if(a==b)cout<<"Draw";
      else cout << ((a==1) ? "Alice" : "Bob");
   }
   return 0;
}
