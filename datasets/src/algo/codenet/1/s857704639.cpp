#include<iostream>
using namespace std;
int main(){
	int c[4][4];
	int i,j;
	int x,y,z;

	for(i=1;i<4;i++)
		for(j=1;j<4;j++)
			cin >> c[i][j];
	x=c[1][1]+c[2][2]+c[3][3];
	y=c[1][2]+c[2][3]+c[3][1];
	z=c[1][3]+c[2][1]+c[3][2];
	if(x==y && x==z && y==z)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}