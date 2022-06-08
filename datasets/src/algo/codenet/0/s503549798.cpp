#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin>>s;
	long long int k; cin>>k;
	long long int n=s.length();
	long long int x=0; long long int c=0;
	
	long long int lc=-1;
	for(long long int i=1;i<n;i++){
		if(s[i]==s[i-1]){
			if(lc==i-1) continue;
			c++; lc=i;
		}
	}
  
  if(s[0]==s[n-1] and lc != n-1) x++;

	cout<<(k-1)*x + k*c;

}
