#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 

  // input
  int a,b;
  cin>>a>>b;


  if(a==1 && b!=1)
    cout<<"Alice"<<endl;
  else if(a!=1 && b==1)
    cout<<"Bob"<<endl;
  else if(a==b)
    cout<<"Draw"<<endl;
  else if(a>b)
    cout<<"Alice"<<endl;
  else
    cout<<"Bob"<<endl;
  

	return 0;
}
