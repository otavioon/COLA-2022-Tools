#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;


int main(){
map<string,int> mp;
int N,M;
string a,b;

cin>>N;
for(int i=0;i<N;++i){
  cin>>a;
  auto itr=mp.find(a);
  if(itr!=mp.end()){
    mp[a]+=1;
  }
  else{
    mp[a]=1;
  }
}

cin>>M;
for(int i=0;i<M;++i){
  cin>>b;
  auto itr=mp.find(b);
  if(itr!=mp.end()){
    mp[b]-=1;
  }
  else{
    mp[b]=(-1);
  }
}
int ans=(-1000000);
for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(ans<(itr->second)){
          ans=(itr->second);
        }
    }
cout<<ans<<"\n";
return 0;
}