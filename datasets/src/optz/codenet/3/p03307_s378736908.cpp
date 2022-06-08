#include <bits/stdc++.h>

#include <cstdlib>  // abs() for integer 絶対値求めやつ

#include <cmath>    // abs() for float, and fabs()

#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i = 0; i< (n);i++)

#define SORT(a) sort((a).begin(),(a).end());

#define che(a,string) cout<<string<<":"<<(a)<<endl;

#define ch(a,string) cout<<string<<":"<<(a)<<" ";

using namespace std;

typedef pair<int,int> p;

int main(){
	long long n;
	cin>>n;
	vector<long long> A(n);

	rep(i,n){
	  cin>>A[i];
	  A[i]-=i+1;
	 // ch(A[i],"A[i]");

	  }
	  SORT(A);
	 long long b=A[n/2];
	  long long c=A[n/2+1];
	  long long B,C;
	  
	  rep(i,n){
		  B +=abs(A[i]-b);
		  C +=abs(A[i]-c);
		}
		long long ans=min(B,C);
		cout<<ans<<endl;
}
