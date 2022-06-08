#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int c, sum = 0;
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++){
        cin >> c;
        sum += c;
    }
    if(sum % 3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}