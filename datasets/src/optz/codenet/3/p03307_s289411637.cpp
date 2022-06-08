#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>

using namespace std;


int main(){
  int n;
  long long ans = 0;
  int B =0;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }

  for(int i = 0; i < n; ++i){
    b[i] =  a[i] - (i + 1);
  }
  sort(b.begin(), b.end());

  B = b[n / 2];

  for(int i = 0; i < n; ++i){
    ans += abs(b[i] - B);
  }

  cout << ans << endl;

}
