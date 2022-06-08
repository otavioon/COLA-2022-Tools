#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int n;
	cin>>n;
	int b[110]={};
	fori(n){cin>>b[i];}
	b[n]=INF;
	int ans=0;
	fori(n){
		if(i==0){
   			ans+=b[0];
    	}else if(i==n-1){
      		ans+=b[n-2];
    	}else{
      		ans+=min(b[i-1],b[i]);
    	}
	}
	cout<<ans;
}