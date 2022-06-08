/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
#define endl "\n";
using namespace std;

const long long INF = 4000000000000000001;
const int inf = 1001001001;
const int MOD = 1000000007;
typedef pair<long long,long long> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //When end-of-a-lin bit is 1, times simple N.
    if (M & 1) res = (res * N) % MOD;
    return res %= MOD;
}
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b ;
}



int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    string S;cin >> S;
    long long K;cin >> K;
    bool ok = true;
    for(int i = 0;i<S.size()-1;i++){
        if(S.at(i) != S.at(i+1)) ok = false;
    }
    //全文字同じ時を例外処理
    if(ok){
        cout << (S.size()*K)/2 << endl;
        return 0;
    }
    
    long long times = 0;
    long long count = 1;
    if(S.size() == 1){
        cout << K-1 << endl;
        return 0;
    }
    for(int i = 0;i<S.size()-1;i++){
        if(S.at(i) == S.at(i+1)){
            count++;
            if(i == S.size()-2) times += count/2;
        }
        else {
            times += count/2;
            count = 1;
        }
    }
    long long ans = K*times;
    char C = '?';
    long long ren = 0;
    for(int i = 0;i<S.size();i++){
        if(C == '?'){
            C = S.at(i);
            ren = 1;
            continue;
        }
        if(C == S.at(i)){
            ren++;
        }
        else{
            break;
        }
    }
    ans -= (ren/2)*(K-1);
    long long kaihi = ren;
    for(int i = S.size()-1;i>=0;i--){
        if(C == S.at(i)){
            ren++;
        }
        else{
            break;
        }
    }
    ans -= ((ren-kaihi)/2)*(K-1);
    ans += (ren/2)*(K-1);
    cout << ans << endl;
}