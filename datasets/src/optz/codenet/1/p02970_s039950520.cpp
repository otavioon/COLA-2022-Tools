#include <bits/stdc++.h>

#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int N, D;
    int ans;
    scanf("%d %d", &N, &D);
    REP(int, i, 1, 20){
        if ( i * (2 * D + 1) >= N ){ ans = i; break;}
    }
    printf("%d\n", ans);
    return 0;
}