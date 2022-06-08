#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a,b,c,d,e,f,g,h,i;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	cin >> g >> h >> i;

	/*if(a+d+g+g+h+i == a+d+g+h+i && b+e+h+g+h+i == b+e+h+g+i &&  && a+d+g+d+e+f == a+d+g+e+f && b+e+h+d+e+f == b+d+e+f+h && e+f+i+d+e+f == c+d+e+f+i  && b+e+h+a+b+c == a+b+c+e+h && c+f+i+a+b+c == a+b+c+i+f){
		cout <<"Yes\n";
	} */
	if(a+d+g+a+b+c == a+b+c+d+g || b+e+h+g+h+i == b+e+h+g+i || c+f+i+g+h+i == c+f+i+h+g || b+e+h+a+b+c == a+b+c+e+h || c+f+i+a+b+c == a+b+c+i+f || a+d+g+g+h+i == a+d+g+h+i ||  a+d+g+d+e+f == a+d+g+e+f && b+e+h+d+e+f == b+d+e+f+h ||e+f+i+d+e+f == c+d+e+f+i)
		cout <<"Yes\n";

	else
		cout << "No\n";
	return 0;

}