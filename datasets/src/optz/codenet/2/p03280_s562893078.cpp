#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void POSS(T condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class T> inline void Poss(T condition){ if(condition) cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class T> inline void First(T condition){ if(condition) cout << "First" << endl; else cout << "Second" << endl; }
template<class T = string, class U = char>int character_count(T text, U character){ int ans = 0; for(U i: text){ ans += (i == character); } return ans; }
long power(long base, long exponent, long module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ long root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position move_pattern[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++){ ans += to_string(*i) + " "; } ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }} template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
#define mod long(1e9 + 7)
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl(long(n))
#define fcout cout << fixed << setprecision(10)
#define highest(x) (63 - __builtin_clzl(x))

using int64 = long long;

map< int64, int > prime_factor(int64 n)
{
    map< int64, int > ret;
    for(int64 i = 2; i * i <= n; i++){
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return(ret);
}

int main(){
    int A, B;
    cin >> A >> B;
    cout << (A - 1) * (B - 1) << endl;
}
