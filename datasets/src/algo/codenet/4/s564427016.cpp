#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
 ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int a = n;
    while (1) {
        int c = a;
        bool ok = 1;
        while (c > 0) {
            int di = c % 10;
            if (s.count(di)) {
                ok = 0;
                break;
            }
            c /= 10;
        }
        if (ok) {
            cout << a << endl;
            break;
        }
        a++;
    }
	return 0;
}