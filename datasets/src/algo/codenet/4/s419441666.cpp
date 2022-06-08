#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     int N, K;
     cin >> N >> K;

     vector<bool> D(10, false);

     rep(i, 0, K) {
       int tmp;
       cin >> tmp;
       D.at(tmp) = true;
     }

     for (int i = N;;i++) {
       int i_tmp = i;
       bool ok = true;
       while(i_tmp) {
         if (D.at(i_tmp % 10)) {
           ok = false;
           break;
         }
         else i_tmp /= 10;
       }
       if (ok) {
         cout << i << endl;
         break;
       }
     }
 }
