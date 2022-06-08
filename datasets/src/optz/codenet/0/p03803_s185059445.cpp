#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	if (a==1&&b!=1){
		cout << "Alice" <<'\n';
		
	}
	
	else if (b==1&&a!=1){
		 cout << "Bob" <<'\n';
	}
	
	else if (a==1&&b==1)cout << "Draw" << '\n';
	
	else {
		if (a>b)cout<<"Alice"<<'\n';
		if (a<b)cout<<"Bob"<<'\n';
		else cout<<"Draw"<<'\n';
	}
	// your code goes here
	return 0;
}