#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	auto f = []( long long n ) -> int
	{
		int d = 0;
		while( n > 0 ) {
			d++;
			n /= 10;
		}
		return d;
	};
	vector<long long> vec;
	for( long long i = 2; i * i <= N; i++ ) {
		if( N % i == 0 ) {
			vec.push_back( i );
			if( N / i != i ) vec.push_back( N / i );
		}
	}
	vec.push_back( 1 );
	vec.push_back( N );
	sort( vec.begin(), vec.end() );
	long long A = vec[vec.size() / 2];
	long long B = N / A;
	int ans = max( f( A ), f( B ) );

	cout << ans << endl;
}
