// Template
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
const int MOD = 1000000007;

#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()
#define s_exists(elem, s) s.find(elem)!=s.end()
#define mod_mul(x, y) x*y%MOD
#define mod_add(x, y) (x+y)%MOD
#define mod_sub(x, y) (x-y)%MOD
#define INF_INT 2147483647

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm( long m, long n ){
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    return ((m / gcd(m, n)) * n);
}


long nCr(long n, long r){
    if(n==r || r==0){
        return 1;
    } else {
        return mod_add(nCr(n-1,r),nCr(n-1,r-1));
    }
}



int main(){
    
    long long N; cin >> N;
    std::multiset<long long> s;
    for(long long i=0;i<N;i++){
        long long temp; cin >> temp;
        s.insert(temp);
    }

    long long cnt = 0;

    while(!s.empty()){
        multiset<long long>::iterator it = std::prev(s.end());
        long long x = *it; s.erase(it);
        long long k = 1LL;
        while(x >= k) k <<= 1;
        it = s.find(k-x);
        if(it!=s.end()){
            ++cnt;
            s.erase(it);
        }
    }

    cout << cnt << endl;
    
    return 0;

}
