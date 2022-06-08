#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  int n, m;
  map<string, int> mp;

  cin >> n;
  for (int i; i<n; i++) {
    string a;
    cin >> a;
    mp[a]+=1;
  }

  cin >> m;
  for (int i=0; i<m; i++) {
    string a;
    cin >> a;
    mp[a]-=1;
  }

  int max=0;
  for (auto itr=mp.begin(); itr!=mp.end(); itr++) {
    if (itr->second>max) max=itr->second;
  }

  printf("%d\n", max);
  return 0;
}