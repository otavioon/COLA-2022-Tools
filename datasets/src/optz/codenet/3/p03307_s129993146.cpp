#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long ll;

using namespace std;

int main()
{
	FastIO;
	int n;
	cin >> n;

	ll arr[n];

	for(int i=0; i<n; i++)
		cin >> arr[i];

	sort(arr, arr+n);

	cout << arr[n-1]-arr[0];
	
	return 0;
}