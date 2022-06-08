#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int c[3][3];
	rep(i,3) rep(j,3) cin>>c[i][j];

	int a1=0,b1=c[0][0],b2=c[0][1],b3=c[0][2];
	int a2=c[1][0]-b1,a3=c[2][0]-b1;

	if(c[1][1]==a2+b2 && c[1][2]==a2+b3 && c[2][1]==a3+b2 && c[2][2]==a3+b3)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}
