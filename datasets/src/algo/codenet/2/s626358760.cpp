#include <iostream>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
//const int MAX=;
//const int MOD=1e9+7;

int lp2(int a){
	int b=log2(a);
	int c=pow(2,b+1);
	return c;
}

int main(){
	int N;
	cin>>N;
	multiset<int> s={};
	rep(i,N){
		int x;
		cin>>x;
		s.insert(x);
	}
	int ans=0;
	while(!s.empty()){
     	multiset<int>::iterator ite0;
      	ite0=s.end();
      --ite0;
		int k=*ite0;
		s.erase(ite0);
     	if(s.empty()) break;
		int l=lp2(k)-k;
		multiset<int>::iterator ite;
		ite=s.find(l);
		if(ite != s.end()){
			ans++;
			s.erase(ite);
		}
	}
	cout<<ans;
}