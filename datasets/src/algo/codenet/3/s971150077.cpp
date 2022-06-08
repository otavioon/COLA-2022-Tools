#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#define LL long long
LL a[100002];
LL b[100002];
LL c[100002];
bool check(LL i1,LL i2,LL i3){
  if ((i1 < i2) and (i2 < i3))
    return true;
  return false;
  }
using namespace std;
int main(){
  LL n,go=0;
  cin>>n;
  for (LL i=0;i<n;i++)
    cin>>a[i]>>b[i]>>c[i];
  sort (a,a+n);
  sort (b,b+n);
  sort (c,c+n);
  for (LL i1=0;i1<n;i1++)
    for (LL i2=0;i2<n;i2++)
      for (LL i3=0;i3<n;i3++)
        if (check(a[i1],b[i2],c[i3]))
           go++;
  cout<<go;
  system ("pause");
  return 0;
  }