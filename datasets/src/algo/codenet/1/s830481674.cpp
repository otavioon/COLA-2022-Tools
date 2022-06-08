#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, y;
    cin >> n >> y;
    
    for (int i = 0; i <=2000; i++){
        for (int j = 0; j <= 2000; j++){
            int k = n - i - j;
            if (k < 0 || 2000 < k) continue;
            if (10 * i + 5 * j + k == y / 1000){
                cout << i << " " << j << " " << k  << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << " " << -1 << " " << -1 << endl;
}
