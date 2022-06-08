#define _GLIBCXX_DEBUG    //空コンテナ操作禁止　Clang環境では#define _LIBCPP_DEBUG 0
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;
using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
  int N;
  cin >> N;
  vector<int> L(N);
  for( int i=0; i<N; i++ ) cin >> L.at(i);
  sort( L.begin(), L.end() );
  
  int ans = 0;
  int num_of_longest;
  for( int i=0; i<N-2; i++ ){
    for( int j=i+1; j<N-1; j++ ){
      num_of_longest = lower_bound( L.begin(), L.end(), L.at(i)+L.at(j) ) - L.begin();
      // Lの要素のうち、keyより小さい要素の数
      ans += num_of_longest - (j+1);
    }
  }
  cout << ans;
  return 0;
}