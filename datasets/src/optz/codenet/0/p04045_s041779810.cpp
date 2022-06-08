#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl 
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl 
#define no cout<<"no"<<endl
#define vec(a,y,x)  vector<vector<char>> a (y,vector<char>(x))
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};
vector<int>a(4,-1);
bool ans(int deg,vector<int> &notd,int n){
  if(deg==0){
    /*rep(i,4)
      cout<<a.at(3-i)<<" ";
    cout<<endl;*/
    if(n<=0) return true;
    else 
    return false;
  }
  
  for(int i : notd){
    a.at(deg-1)=i;
    if(ans(deg-1,notd,n-i*pow(10,deg-1))) return true;
    
  }
  return false;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> d(k),notd;
  rep(i,k)
    cin>>d.at(i);
  rep(i,10){
    if(find(all(d),i)==d.end())
      notd.push_back(i);
  }
  string s=to_string(n);
  int deg=s.size();

  if(!ans(deg,notd,n)){
    if(notd.at(0)!=0)
      cout<<notd.at(0)*10000<<endl;
    else
      cout<<notd.at(1)*10000<<endl;
    return 0;
  }

  rep(i,deg)
    cout<<a.at(deg-1-i);
  cout<<endl;
}