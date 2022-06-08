#include<bits/stdc++.h>

using namespace std;

int main(){
 int n,k;
  cin>>n>>k;
  set<int> st;
  for(int i=0;i<k;i++){
    int x;
    cin>>x;
    st.insert(x);
  }
  for(int i=n;;i++){
    int temp=i,flag=1;;
    while(temp){
      int l=temp%10;
      temp=temp/10;
      if(st.count(l))
        flag=0;
    }
    if(flag){
     cout<<i;
      break;
    }
  }
}