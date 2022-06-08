#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
        */
}

const int MAXN = 200000;
int K,N;
int A[MAXN];
bool ok(double mid) {
    int count = 0;
    rep(i,N) {
        count+=(int)(A[i]/mid);
        if((double)(A[i]/mid) != (int)(A[i]/mid)) {
            count++;
        }
        count--;
    }
    return (count <= K);
}

int up(double x) {
    if(x == int(x))return (int)x;
    else return int(x)+1;
}

int main(){
    cin >> N >> K;
    rep(i,N)cin >> A[i];
    long double mini,maxi,mid;
    mini = 0;
    maxi = LDBL_MAX;

    
    
    while(1) {
        mid = (mini + maxi)/2;
        if(ok(mid)){
            maxi = mid;
        }else {
            mini = mid;
        }
        if(abs(maxi - mini) < 0.01)break;
    }

    cout << up(mid) << endl;
    
    return 0;
}