#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll N;
vector<ll> a;


int main(){
  ll inp;
  ll num=1;
  ll result=0;
  
  cin >> N;
  int checked[100000]={0};
  
  for(int i = 0;i<N;i++){
    cin >> inp;
    a.push_back(inp);
  }
  
  do{
    result++;
    if(a[num-1]==2){
      cout << result << endl;
      return 0;
    }
    else{
      checked[num-1]=1;
      num=a[num-1];
    }
  }while(!checked[num-1]);

  cout << "-1" << endl;
  return 0;
  
}
