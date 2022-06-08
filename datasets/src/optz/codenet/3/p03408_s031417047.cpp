#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
 
int main()
{
  int N, M, count=1, tmp=0, max=0;
  vector<string> s(101), t(101);
  cin >> N;
  rep(i,N){cin >> s.at(i);}
  cin >> M;
  rep(i,M){cin >> t.at(i);}
  rep(i,N)
  {
    rep(j,N)
    {
      if(s.at(j)==s.at(i)&&i<j){count++;}
    }
    rep(k,M)
    {
      if(t.at(k)==s.at(i)){count--;}
    }
    if(tmp<count)
    {
      max=count;
    }
    tmp=max;
  }
  cout << max << endl;
}