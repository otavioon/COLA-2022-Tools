#include <bits/stdc++.h>
using namespace std;


int main() {
  long long int n,k;cin>>n>>k;
  long long msum=0;
  vector<pair<long long,long long>> ab(n);
  for(long long int i=0;i<n;i++){
    long long int a,b;cin>>a>>b;
  	ab[i]=make_pair(a,b);
  }
  
  sort(ab.begin(),ab.end());
  for(long long int i=0;i<n;i++){
  	msum+=ab[i].second;
    if(msum>=k){
    	cout<<ab[i].first<<endl;
      	return 0;
    }
  }
}