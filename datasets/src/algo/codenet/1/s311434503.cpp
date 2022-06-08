#include<iostream>
#include<stdio.h>
using namespace std;
int main(void){
	int c[3][3];
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			cin >> c[i][j];
		}
	}

			if (c[0][0] - c[1][0] == c[0][1] - c[1][1] || c[0][0] - c[2][0] == c[0][1] - c[2][1]){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
}