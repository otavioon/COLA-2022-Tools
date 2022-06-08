#include<bits/stdc++.h>
using namespace std;
using Graph=vector<set<int>>;

int main()
{
  int n,q;
  cin>>n>>q;
  Graph field(n);
  vector<int64_t> point(n,0);
  queue<int> stk;
  for (int i = 1; i < n; ++i)
  {
    field[0].insert(i);
  }
  for (int i = 0; i < n-1; ++i)
  {
    int a,b;
    cin>>a>>b;
    field[a-1].insert(b-1);
  }

  for (int i = 1; i < n ; ++i)
  {
    for(auto&& e: field[i]) {
      stk.push(e);
    }
    while(!stk.empty()){
      int tmp=stk.front();
      stk.pop();
      field[i].insert(tmp);
      for(auto&& e: field[tmp]) {
        stk.push(e);
      }
    }
  }
  /*
  for(auto&& e: field) {
    for(auto&& f: e) {
      cout<<f<<" ";
    }
    cout<<endl;
  }*/
  for (int i = 0; i < q; ++i)
  {
    int a,b;
    cin>>a>>b;
    a--;
    point[a]+=b;
    for(auto&& e: field[a]) {
      point[e]+=b;
    }
  }

  for(auto&& e: point) {
    cout<<e<<" ";
  }
  
}