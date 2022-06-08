#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

ll ans,mx,sum,mn=1e18,cnt;
ll flag;

ll b[3];
int main(){
	ll c1[3],c2[3],c3[3];
	for(ll i=0; i<3; i++){
		cin>>c1[i];
	}
	
	for(ll i=0; i<3; i++){
		cin>>c2[i];
	}
	
	for(ll i=0; i<3; i++){
		cin>>c3[i];
	}
	
	for(ll i=0; i<3; i++){
		if(c2[i] < c1[i] || c3[i]<c1[i]) {
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}

