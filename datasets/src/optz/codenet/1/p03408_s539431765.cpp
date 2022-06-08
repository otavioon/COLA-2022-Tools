#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main (){
  int N;
  cin >> N;
  map<string,int> mp;
  vector<string>t(N);
  for (int i=0;i<N;i++){
    cin >> t[i];
    mp[t[i]]++;
  }
  int M;
  cin >> M;
  vector<string>s(M);
  int a=-100;
  for(int i=0;i<M;i++){
    cin >> s[i];
    mp[s[i]]--;
  }
  for(int i; i<N;i++){
    if(a<=mp[t[i]]){
      a=mp[t[i]];
    }
  }
  cout << a << endl;
}



