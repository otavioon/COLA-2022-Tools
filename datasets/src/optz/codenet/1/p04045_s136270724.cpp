#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, k;
    int d;
    int x;
    bool D[10] = {true, true, true, true, true, true, true, true, true, true};
    cin >> n >> k;
    for(int i = 0; i < 10; i++){
        cin >> d;
        D[d] = false;
    }
    for(int i = n; i < n*10; i++){
        int c = i;
        while(c != 0){
            x = c % 10;
            if(D[x] == false){
                break;
            }
            c /= 10;
            if(c == 0){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}