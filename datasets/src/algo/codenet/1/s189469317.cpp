#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int sum = 0;
    
    for(int x=0;x<9;x++){
        int t;  cin >> t;
        sum += t;
    }
    
    cout << ((sum % 3 == 0 ) ? "Yes" : "No") << endl;
    
    
	return 0;
}
