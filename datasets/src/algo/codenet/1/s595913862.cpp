#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1000000007

int main() {
	ll l[3],r[3];
	for(int i=0;i<3;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		l[i]=b-a;r[i]=c-b;
	}
	bool ans=true;
	for(int i=0;i<2;i++){
		if(l[i]!=l[i+1]||r[i]!=r[i+1]){
			ans=false;
			break;
		}
	}
	cout << (ans? "Yes":"No");
	return 0;
}