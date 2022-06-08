#include<iostream>
#include<sstream>
#include<ios>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<string>
#include<numeric>
#include<set>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using vi = vector<int>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using vpii = vector<pii>;

int main(){
  int N;
  cin >> N;
  vi L(N);
  rep(i, N) cin >> L[i];

  stable_sort(L.begin(), L.end());
  long cnt = 0;
  
  rep_inv(ia, N-1, 1){
    rep_inv(ib, ia-1, 0){
      int Lc = L[ia] - L[ib];
      int left = 0;
      int right = ib - 1;
      int mid;

      if(L[left] > Lc) cnt += (long)(ib);
      else if(L[right] <= Lc) cnt += 0;
      else{
	while(true){
	  mid = left + (right - left) / 2;

	  if(L[mid] > Lc && L[mid - 1] <= Lc) break;
	  else if(L[mid] <= Lc) left = mid + 1;
	  else if(L[mid - 1] > Lc) right = mid;
	}
	cnt += (long)(ib - mid);
      }
    }
  }

  cout << cnt << endl;
  
  return 0;
}