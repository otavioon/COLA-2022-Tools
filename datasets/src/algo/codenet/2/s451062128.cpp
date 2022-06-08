#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void){
  multiset<long,greater<long>>ball;
  size_t n;cin>>n;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    ball.insert(x);
  }
  int ans=0;
  while(!ball.empty()){
    int x=*ball.begin();ball.erase(ball.begin());
    int y=pow(2,(int)log2(x)+1)-x;
    auto it=ball.find(y);
    if(it!=ball.end()){
      ball.erase(it);
      ans+=1;
    }
  }
  cout<<ans<<endl;
}