#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, k;
set<int> d;
int main(){
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int di;
        cin >> di;
        d.insert(di);
    }
    while(true){
        int tmp = n;
        bool ok = true;
        while (tmp != 0) {
            if (d.count(tmp % 10) != 0) {
                ok = false;
                break;
            }
            tmp /= 10;
        }
        if (ok) break;
        n++;
    }
    cout << n << endl;
}
