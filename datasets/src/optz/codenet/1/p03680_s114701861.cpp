#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
    cin >> n;
   vector<int> a(n);
    rep(i,n) {
     cin >> a[i];
    }
 
    
    int b = a.at(0);
    int count = 1;
    for(int i = 0; i < 200000; i++) {
     b = a.at(b-1);
        count++;
        if(b == 2) {
         break;
        }
    }
    
    if(count <= n) {
     cout << count;
    }else {
     cout << -1;}
}