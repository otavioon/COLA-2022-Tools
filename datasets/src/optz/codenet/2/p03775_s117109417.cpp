#include <bits/stdc++.h>

#define INF 100100100
#define MOD 1000000007

using namespace std;
using ll = long long;
using ull = unsigned long long ;

#define FOR(i,n) for(ll i=0;i<n;i++)

ull log_10(ull N){
   ull count = 1;
   double N_ = N;
   while(N_>=10){
      N_/=10;
      count++;
   }
   return count;
}

vector<ull> prime;

int main(int argc, char const* argv[]){
   ios::sync_with_stdio(false);
   cin.tie(0); 

   ull N;
   cin >> N;

   for(int i=1;i*i<=N-1;i++){
      if(N%i==0)prime.push_back(i);
   }

   ull MIN = N;
   for(int i=0;i<prime.size();i++){
      MIN = min(max(prime[i],N/prime[i]),MIN);
   }

   cout << log_10(MIN) << endl;
   return 0;
}
