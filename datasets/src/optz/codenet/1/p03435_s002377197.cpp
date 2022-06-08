#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

int ans;
int c[4][4];


int main(void) {
    rep(i, 1, 4) rep(j, 1, 4) scanf("%d", &c[i][j]);
    
    rep(i, 0, c[1][1]+1) {
      int a[4], b[4];
      a[1] = i;
      rep(j, 1, 4) b[j] = c[1][j] - a[1];
      a[2] = c[2][1] - b[1];
      a[3] = c[3][1] - b[1];
      
      bool ok = true;
      rep(j, 2, 4) rep(k, 2, 4) {
        if (c[j][k] != a[j] + b[k]) ok = false;
      }
      if (ok) {
        puts("Yes");
        return 0;
      }
      
    }

    puts("No");
    return 0;
}
