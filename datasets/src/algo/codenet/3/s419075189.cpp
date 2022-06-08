//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=100001;
int stoio(std::string str){
    int ret;
    stringstream ss;
    ss << str;
    ss >> ret;
return ret;
}
int main(){
  int n;
  cin>>n;
  int a[100004],b[100004],c[100004];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  for(int i=0;i<n;i++) cin>>c[i];
  sort(a,a+(n));
  sort(c,c+(n));
  ll ans=0;
  for(int i=0;i<n;i++){
    int l=-1,r=n,mid;
    while(r-l>1){
      mid=(l+r)/2;
      if(a[mid]>b[i])r=mid;
      else l=mid;
    }
  
    int tmp=r;
    l=-1,r=n;
    while(r-l>1){
      mid=(l+r)/2;
      if(c[mid]>b[i])r=mid;
      else l=mid;
    }
    ans+=(tmp*(n-r));
  }
  
  cout<<ans<<endl;
  
  return 0;
}
