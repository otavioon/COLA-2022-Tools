#include <iostream>
#define ll long long
using namespace std;

int main(){
  string s;
  ll k;
  cin >> s >> k;
  
  if(s.size()==1){cout << s.size()/2;}
  else{
    ll head=1; ll tail=1; int i=1; ll tot=0; ll c=1;
    while(s[i]==s[i-1]){head++; i++;}
    
    for(int j=1; j<s.size(); j++){
    	if(s[j]==s[j-1]){c++;}
    	else if(c>1){
      		tot = tot+c/2;
      		c=1;
        }
    }
    tail=c; tot = tot+c/2; tot = tot*k;
    
    if(s[0]==s[s.size()-1] && head%2==1 && tail%2==1){
    	tot = tot+k-1;
    }
    cout << tot;
  }
  
  
  
  return 0;
}