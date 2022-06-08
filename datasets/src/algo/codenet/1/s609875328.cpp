#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int sum = 0;
    
    for(int x=0;x<9;x++){
        int t;  cin >> t;
        sum += t;
    }
    
    if(sum < 0) sum *= (-1);
    
    cout << ((sum % 3 == 0 ) ? "Yes" : "No") << endl;
    
    
	return 0;
}
