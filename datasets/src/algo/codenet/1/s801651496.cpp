#include<bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
	for(int i = 1; i <= 9; i++){
		cin >> a[i];
	}
	if(a[1] + a[5] + a[9] == a[2] + a[6] + a[7] &&
	   a[1] + a[5] + a[9] == a[3] + a[4] + a[8]) puts("Yes");
	   else puts("No");
	return 0;
}