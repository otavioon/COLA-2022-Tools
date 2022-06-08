#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int n;
int a[100010];
int b[100010];
int c[100010];

int main() {    
    cin >> n;
    imfor(i, n) {
        cin >> a[i];
    }
    imfor(i, n) {
        cin >> b[i];
    }
    imfor(i, n) {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(c, c + n);
    ll ans = 0;
    imfor(i, n) {
        int lb = -1, ub = n;
        while(ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (a[mid] >= b[i]) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        int ai = ub;

        lb = -1, ub = n;
        while(ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (c[mid] >= b[i] + 1) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        int ci = n - ub;
        //cout << ai << " " << ci << endl;
        ans += ai * ci;
    }
    cout << ans << endl;
}