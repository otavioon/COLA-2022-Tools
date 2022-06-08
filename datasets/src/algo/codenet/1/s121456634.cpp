#include<iostream>
using namespace std;

int main(){
	int c[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>c[i][j];
		}
	}
	
	int x=0,y=0;
	for(int i=0;i<2;i++){
		x+=c[i][i];
		
		for(int j=0;j<2;j++){
			y+=c[i][j];
		}
	}
	
	x*=3;
	
	if(x==y) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}