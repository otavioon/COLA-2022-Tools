#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int c[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			if(c[i][0]-c[0][0] != c[i][j]-c[0][j]){
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
