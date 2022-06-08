#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  map<string, int> s;
  string s_tmp;
  for (int i=0;i<N;i++){
    cin >> s_tmp;
    s[s_tmp]++;
  }

  int M;
  cin >> M;
  for (int i=0;i<M;i++){
    cin >> s_tmp;
    s[s_tmp]--;
  }
  
  int retval = 0;
  for (auto p : s){
    if (p.second>0) retval = max(p.second,retval);
  }
  cout << retval << endl;
}