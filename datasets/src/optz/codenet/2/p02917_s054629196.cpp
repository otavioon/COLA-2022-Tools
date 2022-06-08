#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,i,x;
	int a[110]; 
	cin >> n;
	for(i=1;i<n;i++){
		cin >> a[i];
	}
	a[n]=a[n-1];
	x=a[1];
	for(i=1;i<n;i++){
		if(a[i]<a[i+1])
			x+=a[i];
		else
			x+=a[i+1];
	}
	cout << x << endl; 
	return 0;
}
