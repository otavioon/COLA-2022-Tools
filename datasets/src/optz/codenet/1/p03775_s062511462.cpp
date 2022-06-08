#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int NumberOfFigure(long long X){
	long long count = 1;
	if( X > 9 ){
		count = 0;
		for( int i = 0; i < 10; i++ ){
			if( X == 0 ){
			break;
			}
			else{
			count += 1;
			X /= 10;
			}
		}
	}
	return count;
}

int main(){
	long long N;
	long long n = sqrt(N);
	int ans;
	
	for(long long i = n; i <= N; i++){
		for(long long j = 1; j <= n; j++){
			if(i * j == N){
				ans = NumberOfFigure(i);
				break;
			}
		}
	}
	
	cout << ans << endl;
}