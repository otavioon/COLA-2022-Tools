#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//*************************************************************
//*  ????1000012846_1.cpp *********************************
//*  ????? ***********************************************
//*  ?????2010?11? *************************************
//*  ????????? ***************************************
//*************************************************************
void o( char a[] , int m , int n )     //?????????????????????
{
	int p = m , q = n ;      //????
	for ( ; ; )
	{
		if (a[m+1] != a[n-1] )
			break ;
		if ( n - m <= 2 )
		{
			for ( int i = p ; i <= q ; i++ )
				cout << a[i] ;
			cout << endl ;
			break ;
		}
		m++ ;
		n-- ;
	}
}
int main()
{
	char a[500] , i , j , k , len ;   //??????i,j,k;????len;
	cin >> a ;          //?????
	len = strlen ( a ) ;
	for ( k = 1 ; k < len ; k++ )
		for ( i = 0 ; i < len ; i++ )
			for ( j = i + 1 ; j < len ; j++ )
				if ( a[i] == a[j] && j - i == k )
					o(a,i,j) ;         //????o()
	return 0;
}