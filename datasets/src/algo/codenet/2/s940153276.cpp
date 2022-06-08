
// in the name of Allah ;
#include<bits/stdc++.h>
using namespace std;
const int lg = 40 ;
int t[lg] , n ;
multiset < int > st ;
void init()
{
	t[0] = 1 ;
	for ( int i = 0 ; i < lg -1 ; i++ ) 
		t[i+1] = t[i]*2 ;
}
void input() 
{
	cin >> n ;
	int x ;
	for ( int i = 0 ; i < n ; i++ ) 
		cin >> x , st.insert ( x ) ;
}
int main () 
{
	init() ;
	input() ;
	int ans = 0 ;
	while ( st.size() )
	{
		int x = *st.rbegin() ;
		st.erase ( st.find(x) ) ;
		for ( int j = lg-1 ; j >= 0 ; j-- ) 
		{
			if ( st.find ( t[j] - x ) != st.end() ) 
			{
				ans++ , st.erase ( st.find ( t[j]-x ) ) ;
				break;
			}
		}
	}
	cout << ans << endl;
}