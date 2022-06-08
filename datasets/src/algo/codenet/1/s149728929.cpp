#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;

int main() {
  int c[9],sum=0;
  bool f=true;
  for(int i=0;i<9;i++){
    cin>>c[i];
    sum+=c[i];
  }

  if(3*(c[0]+c[4]+c[8])!=sum) f=false;

  if(f) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}	
