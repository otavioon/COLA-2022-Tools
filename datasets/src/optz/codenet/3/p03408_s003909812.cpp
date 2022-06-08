#include<bits/stdc++.h>
using namespace std;

int main(){
int N,M;
  cin>>N;
  vector<string>S(N);
  for(int i=0; i<N; i++){
   cin>>S[i]; }
  
  cin>>M;
  vector<string>T(M);
  for(int i=0; i<M; i++){
   cin>>T[i]; }
  
  vector<int>count(110);
  for(int i=0; i<N; i++){
   for(int j=0; j<N; j++){
    if(S[i]==S[j]){count[i]++;} }}

  for(int i=0; i<N; i++){
   for(int j=0; j<M; j++){
    if(S[i]==T[j]){count[i]--;} }}
  
  int ans=*max_element(count.begin(), count.end());
  cout<<ans;
}