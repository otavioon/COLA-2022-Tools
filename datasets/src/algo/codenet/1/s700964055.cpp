#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[9];
  for(int i=0;i<9;i++) cin>>a[i];
  int b=a[0]-a[1],c=a[0]-a[2];
  if(a[3]-a[4]==b&&a[3]-a[5]==c&&a[6]-a[7]==b&&a[6]-a[8]==c)cout<<"Yes";
else cout<<"No";
}