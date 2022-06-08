#include <iostream>
using namespace std;
int a[9];
int main() {
	int i;
	for(i=0; i<9; i++) cin>>a[i];
	for(i=8; i>2; i--) a[i] -= a[i-3];
	cout<<(a[3]==a[4] && a[4]==a[5] && a[6]==a[7] && a[7]==a[8] ? "Yes":"No");
	return 0;
}