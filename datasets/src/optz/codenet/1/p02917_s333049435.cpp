#include <bits/stdc++.h>
using namespace std;

int main( ) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,i,a,b;
    t = 1;
    while(t--) {
     a = 0;
	 cin >> n;
	 int arr[n - 1];
	 for(i = 0; i < n - 1; i++)
	  cin >> arr[i];
	 for(i = n - 2; i > 0; i--) {
	  if(arr[i] < arr[i - 1])
	   arr[i - 1] = arr[i];
	 }
	 for(i = 0; i < n - 1; i++) {
	  if(i > 0)
	   a = a + arr[i];
	  else
	   a = a + arr[i] * 2;
	 }
	 cout << a << endl;
    }
    return 0;
}

