#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<list>
#include<vector>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main(){

	int a[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			
		cin >> a[i][j];
		}
	}

	int maa=0,mab=0,mac=0,mad=0,mae=0,maf=0;
	maa= min(min(a[0][0],a[0][1]),a[0][2]);
	mab= min(min(a[1][0],a[1][1]),a[1][2]);
	mac= min(min(a[2][0],a[2][1]),a[2][2]);
	mad= min(min(a[0][0],a[1][0]),a[2][0]);
	mae= min(min(a[0][1],a[1][1]),a[2][1]);
	maf= min(min(a[0][2],a[1][2]),a[2][2]);

	for(int k=0;k<=maa;k++){
		for(int p=0;p<=mab;p++){
			for(int u=0;u<=mac;u++){
				for(int h=0;h<=a[0][0]-k;h++){
					for(int n=0;n<=a[1][1]-p;n++){
						for(int m=0;m<=a[2][2]-u;m++){
							if(k+h==a[0][0]){

								if(k+n==a[0][1]&&k+m==a[0][2]&&p+h==a[1][0]&&p+n==a[1][1]&&p+m==a[1][2]&&u+h==a[2][0]&&u+n==a[2][1]&&u+m==a[2][2]){
							cout << "Yes" << endl;
							return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
