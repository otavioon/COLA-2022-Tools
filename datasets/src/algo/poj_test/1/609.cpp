#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
 * 6-4.cpp
 *
 *  Created on: 2011-10-28
 *      Author: wuch
 */



int main(){
	int row,col,i,j; //??row?col????i?j
	int array[100][100]; //??????array
	cin>>row>>col;
	for (i=1;i<=row;i++)  //????
		for (j=1;j<=col;j++) cin>>array[i][j];
	for (i=2;i<=row+col;i++)  //?? ?+? ???????????????????
		for (j=1;j<=i-1;j++){
			if ((j<=row)&&(i-j<=col)) cout<<array[j][i-j]<<endl; //????????
		}
	return 0;
}
