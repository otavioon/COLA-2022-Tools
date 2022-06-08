#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

//-----------------------------------------------

//------------------------------------------------
int main(){
  int n,d,w,answer;
  cin>>n>>d;
  w=0;
  answer=0;
  rep(i,0,n){
    w+=2*d+1;
    answer+=1;
    if(w>=n) break;
  }


  cout<<answer<<endl;
}
