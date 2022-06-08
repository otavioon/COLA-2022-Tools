#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main()
{
	int n, down = 0, up = 0;
	LLI ans = 0;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a,a+n);
	
	for(int i = 0; i < n; i++)
		cin >> b[i];
	sort(b,b+n);
	
	for(int i = 0; i < n; i++)
		cin >> c[i];
	sort(c,c+n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = down; j < n; j++)
			if( b[i] > a[j] )
				down++;
			else
				break;
		for(int j = up; j < n; j++)
			if( b[i] >= c[j] )
				up++;
			else
				break;
		ans += (LLI)down * (LLI)( n - up );
	}
	cout << ans;
}