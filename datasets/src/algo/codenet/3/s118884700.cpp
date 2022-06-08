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
int a[111111];
int b[111111];
int c[111111];

/*
 */
int binary_search_a(int num);
/*
 */
int binary_search_c(int num);

int main(){
  ios_base::sync_with_stdio(false);

  long long ans = 0;

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
  sort(c, c+n);

  for(int i=0;i<n;i++){
    long long aa = binary_search_a(b[i]);
    long long cc = binary_search_c(b[i]);
    ans += aa * cc;
  }    

  cout << ans << endl;

  return 0;
}

int binary_search_a(int num){
  int ng = -1;
  int ok = n;
  int mid = abs(ok - ng);

  while(abs(ok - ng) > 1){
    mid = (ok + ng) / 2;
    if(num <= a[mid]){
      ok = mid;   
    } else {
      ng = mid;
    }
  }
  
  return ok;
}

int binary_search_c(int num){
  int ng = -1;
  int ok = n;
  int mid = abs(ok - ng);

  while(abs(ok - ng) > 1){
    mid = (ok + ng) / 2;
    if(num < c[mid]){
      ok = mid; 
    } else {
      ng = mid;
    }
  }

  return (n - ok);
}
