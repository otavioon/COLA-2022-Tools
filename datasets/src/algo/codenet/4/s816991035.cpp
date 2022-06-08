#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)


typedef long long ll;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

int main() {
    int N; cin >> N;
    int K; cin >> K;
    set<int> D;
    repp(i, 0, K) {
        int d; cin >> d;
        D.insert(d);
    }
    long long res = N;
    while(true) {
        bool ok = true;
        long long t_res = res;
        while(t_res > 0) {
             ok &= D.find(t_res % 10) == D.end();
             t_res /= 10;
        }
        if (ok) {
            cout << res << endl;
            return 0;
        } else {
            ++res;
        }
    }
}