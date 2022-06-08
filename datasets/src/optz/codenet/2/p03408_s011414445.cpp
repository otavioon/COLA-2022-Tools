#include <bits/stdc++.h>
using namespace std;

int main(){
  map<string,int> Red;
  map<string,int> Blue;

  int N;
  cin>>N;
  vector<string> s(N);
  for(int i=0;i<N;++i){
    cin>>s.at(i);
    Red[s.at(i)]+=1;
  }

  int M;
  cin>>M;
  vector<string> t(M);
  for(int i=0;i<M;++i){
    cin>>t.at(i);
    Blue[t.at(i)]+=1;
  }

  int ans=0;
  for(int i=0;i<N;++i){
    int score=0;
    if(Blue[s.at(i)]>0){
      score=Red[s.at(i)]-Blue[s.at(i)];
    }
    else{
      score=Red[s.at(i)];
    }
    if(ans<score){
      ans=score;
    }
  }

  cout<<ans<<endl;
}