#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};



int main() {
    int a[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};
    int A, B;
    cin >> A >> B;
    int iA, iB;
    for (int i = 0; i < 13; i++) {
        if (a[i] == A) {
            iA = i;
        }
        if (a[i] == B) {
            iB = i;
        }
    }
    if (iA > iB) {
        cout << "Alice" << endl;
    } else if (iA < iB) {
        cout << "Bob" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}