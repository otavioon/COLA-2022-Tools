#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,s;
  int b[2100];
  cin >> a ;
  for(int i=0;i<a;i++){
    cin >> b[i];
  }
  for(int i=0;i<a;i++){
    if(b[i]>b[i+1])continue;
    for(int j=i+1;j<a;j++){
      if(b[j]>b[j+1])continue;
      for(int k=j+1;k<a;k++){
        if(b[k]>b[k+1])continue;
        if(b[i]<b[j]+b[k]&&b[j]<b[i]+b[k]&&b[k]<b[j]+b[i]){
          s=s+1;
        }
      }
    }
  }


  cout << s << endl;
}