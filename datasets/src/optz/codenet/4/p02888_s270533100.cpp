#include "bits/stdc++.h"
using namespace std ;


int a[3000] ;
int p[3000] ;
int L[3000] ;
int main(){
	int n , l ;
	cin >> n ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> l ;
		L[i] = l ;
		a[l]++ ; 
	}
	for( int i = 1 ; i < 3000 ; i++ ){
		p[i] = p[i-1] + a[i ] ;
	}
	long long count = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		for( int j = i+1 ; j < n ; j++ ){
			int a = L[i] ;
			int b = L[j] ;
			int m  = abs(a-b) ;
			int M = a+b ;
			int ans = p[M-1] - p[m] ;
			if( m < a && a < M ) ans-- ;
			if( m < b && b < M) ans-- ;
			// cout << a << " " << b << " " <<m   << " " <<M << " " << p[M-1] - p[m] << endl ;
			count += ( max(0,ans) );
		}
	}
	cout << count / 3 << endl ;



	return 0 ;
}