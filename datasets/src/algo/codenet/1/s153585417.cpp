#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>

#include <map>
 
using namespace std;
typedef long long ll; 

ll gcd(ll a,ll b){ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);        
} 

ll lcm(ll a,ll b) {  
    return (a*b)/gcd(a, b);  
}  

ll ans,mx,sum,mn=1e10,flag;
ll a[10000000],b[1000000];
int main(){
	ll a[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>a[i][j];
		}
	}
	if(a[0][0]==a[1][1]||a[1][1]==a[2][2]) cout<<"Yes";
	else cout<<"No";
}

