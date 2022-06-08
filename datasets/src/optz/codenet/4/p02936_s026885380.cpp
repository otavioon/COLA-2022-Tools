#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,q;
  cin >>n>>q;
  vector<int> a(n-1),b(n-1);
  vector<int>t[n],c(n);

  rep(i,n-1) {
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
    t[b.at(i)].push_back(a.at(i));
    t[a.at(i)].push_back(b.at(i));
  }
  vector<int>p(q),x(q);
  rep(i,q){
    cin>>p.at(i)>>x.at(i);
    p.at(i)--;
    c[p.at(i)]+=x.at(i);
  }
  vector<int>ans(n);
  queue<int>que;
  que.push(0);
  ans.at(0)=c.at(0);
  vector<bool>v(n,false);
  v.at(0)=true;
  while(!que.empty()){
    int p=que.front();que.pop();
    rep(j,t[p].size()){
      if(!v.at(t[p].at(j))){
        que.push(t[p].at(j));
        ans.at(t[p].at(j))=ans.at(p)+c.at(t[p].at(j));
        v.at(t[p].at(j))=true;
      }
    }
  }
  
  rep(i,n){
    cout<<ans.at(i)<<" ";
  }
}