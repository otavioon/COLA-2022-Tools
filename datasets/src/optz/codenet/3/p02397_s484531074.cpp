#include "bits/stdc++.h"
using namespace std;

int main(){
  vector<int> a(2);
  while(1){
    cin>>a[0]>>a[1];
    if(a[0]==a[1]&&a[0]==0)break;
    sort(a.begin(),a.end());
    cout<<a[0]<<" "<<a[1]<<endl;
    
  }
}

