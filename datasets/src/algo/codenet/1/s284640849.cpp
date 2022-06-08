#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int c[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;1<3;i++){
		if(c[i][0]-c[0][0]!=c[i][1]-c[0][1] || c[i][2]-c[0][2]!=c[i][1]-c[0][1]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
