#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if(a!=1 && b!=1){
        if(a>b){
            cout << "Alice" << endl;
        }else if (a==b){
            cout << "Draw" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }else{
        if(a==b){
            cout << "Draw" << endl;
        }else{
            if(a<b){
                cout << "Alice" << endl;
            }else{
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}