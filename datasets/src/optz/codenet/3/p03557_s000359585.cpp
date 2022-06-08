#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;

using namespace std;

int main()
{ll N; cin >> N;
vector<ll> A(N); vector<ll>B(N); vector<ll>C(N);
 
for(ll i = 0; i < N;i++){ cin >> A[i];}
 for(ll j = 0; j < N; j++){ cin >> B[j];}
  for(ll k = 0; k < N; k++){ cin >> C[k];}
 
 sort(A.begin(),A.end());
 sort(B.begin(),B.end());
 sort(C.begin(),C.end());
 
 ll total = 0;
 
 for(ll j = 0; j < N; j++){
   ll key = B[j];
   auto position1 = lower_bound(A.begin(),A.end(),key);
   auto position2 = upper_bound(C.begin(),C.end(),key);
   
   ll cntA = distance(A.begin(), position1);
   ll cntB = distance(position2,C.end());
   
   
    total += cntA * cntB;
 }
 
 cout << total << endl;
 
 return 0;
}
