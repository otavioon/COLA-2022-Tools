#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
 * seperateThenumber.cpp
 *
 *  Created on: 2012-11-13
 *      Author: AK
 */
int sum=1;                                    //??????sum  ??f???sum?????
void f(int begin,int m){                       //??f??
	int i;
	for(i=begin;i<=m;i++){                     //?i???????????
		if(m%i==0&&m/i>=i){sum++;f(i,m/i);}    //?????????????????   ????????????
		if(i>m/i) break;                       //?????????????break
	}
}
int main(){
	int n,j,m;
	cin>>n;                         //????????n
	for(j=1;j<=n;j++){               //???????
		cin>>m;
		f(2,m);
		cout<<sum<<endl;                 //??sum?
		sum=1;           //??sum=1
	}
	return 0;
}
