#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[4][4];
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++) cin>>a[i][j];
	}
	if((a[1][2]+a[2][3]+a[3][1]+a[1][3]+a[2][1]+a[3][2])==(a[1][1]+a[2][2]+a[3][3])*2) cout<<"Yes\n";
	else  cout<<"No\n";
    return 0;
}