#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int n;
int a[111111], b[111111], c[111111];

int BinarySearch(int *d, int num); 

int main(){
  ios_base::sync_with_stdio(false);

  int ans = 0;

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
  }
  for(int i=0;i<n;i++){
    cin >> c[i];
  }

  sort(a, a+n);
  sort(b, b+n);
  sort(c, c+n);

  for(int i=0;i<n;i++){
    int aa = BinarySearch(a, b[i]);
    int cc = BinarySearch(c, b[i]);
    if(c[cc] == b[i]){
      cc++;
    }
    //cout << "ans += " << aa << " * (n - " << cc << ") = " << aa*(n-cc) << endl;
    cc = n - cc;
    ans += aa * cc;
  }

  cout << ans << endl;

  return 0;
}

int BinarySearch(int *d, int num){
  int ok = 0;
  int ng = n;
  int mid = (ok + ng) / 2;

  while(ng - ok > 1){
    if(num < d[mid]){
      ng = mid;
    } else {
      ok = mid;
    }
    mid = (ok + ng) / 2;
  }

  if(mid == 0 && num < d[mid]){
    return 0;
  }
  if(num == d[mid])return mid; 
  return mid + 1;
}
