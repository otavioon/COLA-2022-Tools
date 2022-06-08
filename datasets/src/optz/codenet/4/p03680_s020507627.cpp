#include<bits/stdc++.h>
using namespace std;
#include<set>

int main(){
  int N;

  cin>>N;
  vector<int> a(N);

  int i;
  for(i=0;i<N;i++)
  cin>>a.at(i);

  set<int> st;
  int cnt=0;
  bool hand=false;
  i=0;
  while(st.count(i)==0){
    // cout<<"syori"<<endl;
    cnt++;
    st.insert(i);
    i=a.at(i)-1;
    if(i==1){
      hand=true;
      break;
    }
  }
  if(hand)
  cout<<cnt<<endl;
  else
  cout<<-1<<endl;

}
