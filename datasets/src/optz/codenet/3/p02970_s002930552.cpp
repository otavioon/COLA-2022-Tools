#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
using namespace std;


typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
  int n, d;
  cin >> n >> d;
  int ans = 0;
  int now = 0;
  while(true){

    if(now + 2 * d + 1 > n){
      break;
    } else {
      now += 2 * d + 1 ;
      ans ++;
    }
  }
  if(now - n != 0) ans++;

  cout << ans << endl;


}
