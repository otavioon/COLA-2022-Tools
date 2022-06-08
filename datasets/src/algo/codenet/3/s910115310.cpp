#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;

int n;
long long a[100005];
long long b[100005];
long long c[100005];


int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n;i++)cin>>c[i];

  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  long long ans[100005];

  int p=0;
  for(int i=0;i<n;i++){
    while(c[p] <= b[i]){
      if(p==n) break;
      p++;
    }
    ans[i] = n-p;
  }

  for(int i=n-2;i>=0;i--)ans[i] += ans[i+1];

  long long ans2 = 0;
  p=0;
  for(int i=0;i<n;i++){
    while(b[p] <= a[i]){
      if(p==n) break;
      p++;
    }
    if(p == n) continue;
    ans2 += ans[p];
  }

  cout<<ans2<<endl;
  return 0;
}