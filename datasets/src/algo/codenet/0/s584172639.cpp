#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string a,b,f,g;
  ll c,d,e,h,i;
  cin >> a >>i;
  e=0;
  b=a[0];
  d=1;
  for(c=1;c<(ll)a.size();c++){
    f=a[c];
    if(b==f){
      d+=1;
    }
    else if(e==0){
      g=b;
      b=f;
      e+=floor(d/2);
      h=d%2;
      d=1;
    }
    else{
      b=f;
      e+=floor(d/2);
      d=1;
    }
  }
  if(d==a.size()){
    e=floor(i*a.size()/2);
  }
  else if(f==g){
  	e+=floor(d/2);
    e=e*i+(h*d%2)*(i-1);
  }
  else{
  	e+=floor(d/2);
    e=e*i;
  }
  cout << e << endl;
}