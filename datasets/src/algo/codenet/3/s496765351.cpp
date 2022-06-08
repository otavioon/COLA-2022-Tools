#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <limits>
#include <set>
#include <map>
#include <type_traits>
#include <cstdint>
 
typedef long long ll;
 
using namespace std;

ll N;
ll A[100010],B[100010],C[100010];
bool AisOK(ll index, ll key)
{ 
  	if(A[index] < key) return true;
    else return false;
}
bool CisOK(ll index, ll key)
{ 
  	if(C[index] > key) return true;
    else return false;
}
ll binary_search(ll key)
{
  ll Al = -1;
  ll Ar = N;
  
  while(Ar > Al+1)
  {
    ll mid = Al +(Ar - Al)/2;  
    if(AisOK(mid,key)) Al = mid;
    else Ar = mid;
  }
  
  ll Cl = -1;
  ll Cr = N;
  
  while(Cr > Cl+1)
  {
    ll mid = Cl +(Cr - Cl)/2;
    if(CisOK(mid,key)) Cr = mid;
    else Cl = mid;
  }
  
  return Ar*(N-Cl-1);
}
int main()
{
  cin >> N;
  for(ll i=0;i<N;i++)cin >> A[i];
  for(ll i=0;i<N;i++)cin >> B[i];
  for(ll i=0;i<N;i++)cin >> C[i];
  sort(A,A+N);
  sort(B,B+N);
  sort(C,C+N);
  
  ll ans = 0;
  for(ll i=0;i<N;i++)
    ans+=binary_search(B[i]);
  
  cout << ans << endl;  
  
  return 0;
}