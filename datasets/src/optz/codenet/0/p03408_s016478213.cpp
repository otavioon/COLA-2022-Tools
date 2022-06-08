#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,k;
  string kari;
  vector<string> a;
  vector<string> b;
  vector<int> a_count(1,1);
  
  cin >> N;
  cin >> kari;
  a.push_back(kari);
  for(int i=1;i<N;i++){
    cin >> kari;//i th input
    k=a.size();
    auto aiueo=[&kari](string species){return kari==species;};
    for(int j=0;j<k;j++){
      if(a.at(j)==kari){
        a_count.at(j)++;
        break;
      }
    }
    if(none_of(a.cbegin(),a.cend(),aiueo)){
      a.push_back(kari);
      a_count.push_back(1);
    }
  }
  vector<int> b_count(a.size(),0);
  cin >> M;
  for(int i=0;i<M;i++){
    cin >> kari;
    for(int j=0;j<a.size();j++){
      if(a.at(j)==kari){
        b_count.at(j)++;
        break;
      }
    }
  }
  k=0;
  for(int i=0;i<a_count.size();i++){
    k=max(k,max(a_count.at(i)-b_count.at(i),0));
  }
  cout << k << endl;
}
