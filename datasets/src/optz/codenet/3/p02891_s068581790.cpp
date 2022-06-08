/**/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>

typedef long long int63;
using namespace std;
#define forl(name,start,end,jump) for(int63 name = start; name < end; name+=jump)
#define forlb(name,start,end,jump) for(int63 name = end - 1; name >= start; name+=jump)
#define forn(name,start,end) forl(name,start,end,1)
#define fornb(name,start,end) forlb(name,start,end,-1)
#define fort(start,end) forn(i,start,end)
#define fortb(start,end) fornb(i,start,end)
#define forto(start,end) forn(j,start,end)
#define fortoo(start,end) forn(l,start,end)
#define all(vec) vec.begin(),vec.end()
#define makeitem(itemname,itemtype) itemtype itemname; cin >> itemname
#define makeint(intname) int63 intname; cin >> intname
#define makeN int63 n; cin >> n
#define makeM int63 m; cin >> m
#define makeL int63 l; cin >> l
#define makeT int63 t; cin >> t
#define makeK int63 k; cin >> k
#define point pair<int63,int63>
#define matrix(type) vector<vector<type>>
#define in(name) cin >> name;
#define tosort(name) name.begin(),name.end()
int63 powmod(int63 base, int63 exponent, int63 mod) {
    int63 result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 0) {
            exponent /= 2;
            base = (base * base) % mod;
        } else {
            result = (result * base) % mod;
            exponent /= 2;
            base = (base * base) % mod;
        }
    }
    return result;
}
bool decresing(int63 x, int63 y) {
    return x > y;
}

int63 trin(int63 start, int63 stop) {
    return (stop - start + 1) * (stop + start) / 2;
}

bool sortvectorf(point a, point b) {
return((a.first > b.first) || (a.first == b.first && a.second > b.second));
}

bool sortvectordiv(point a, point b) {
    
    return a.first * b.second > b.first * a.second;
}

bool sortvectorfv(point a, point b) {
    return((a.first > b.first) || (a.first == b.first && a.second < b.second));
}

bool sortvectors(point a, point b) {
return((a.second > b.second) || (a.second == b.second && a.first > b.first));
}

bool negasortvectorf(point a, point b) {
return((a.first < b.first) || (a.first == b.first && a.second < b.second));
}

bool negasortvectors(point a, point b) {
return((a.second < b.second) || (a.second == b.second && a.first < b.first));
}

vector<vector<int63>> findPermutations(vector<int63> &a)
{

    // Sort the given array
    sort(a.begin(), a.end());
    vector<vector<int63> > sol;
    // Find all possible permutations
    do {
        sol.push_back(a);
    } while (next_permutation(a.begin(),a.end()));
    return sol;
}

int63 gcd(int63 a, int63 b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b % a, a);
}

bool isprime(int63 n) {
    fort(2, n) {
        if (i * i > n) {
            break;
        }
        if ((n / i) * i == n) {
            return false;
        }
    }
    return true;
}

int63 fdivisor(int63 n,int63 fro) {
    fort(1, n + 1) {
        if ((n / i) * i == n && i >= fro) {
            return i;
        }
    }
    return -1;
}

vector<int63> divlist(int63 n) {
    vector<int63> curr;
    fort(2, n) {
        if ((int63)i * i > n) {
            break;
        }
        if ((n / i) * i == n) {
            curr.push_back(i);
            curr.push_back(n / i);
        }
        if ((int63)i * i == n) {
            curr.pop_back();
        }
    }

    sort(all(curr));
    return curr;
}
int63 countdivisors(int63 n,int63 divd,int63 rem) {
    vector<int63> divs = divlist(n);
    int63 tot = 0;
    fort(0, divs.size()) {
        if (divs[i] % divd == rem) {
            tot++;
        }
    }
    if (n % divd == rem) {
        tot++;
    }
    return tot;
}
int63 digsum(int63 num) {
    int63 cr = 0;
    while (num > 0) {
        cr += num % 10;
        num /= 10;
    }
    return cr;
}

int63 modInverse(int63 a, int63 b) {
    int63 m = b;
    int63 y = 0, x = 1;
    while (a > 1) {
        int63 q = a / m;
        int63 t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += b;
    }
    return x;
}
int63 azeret(int63 num, int63 mod) {
    int63 sil = 1;
    while (num > 1) {
        sil *= num;
        sil %= mod;
        num--;
    }
    return sil;
}
int63 moddiv(int63 to, int63 by, int63 mod) {
    to %= mod;
    while (to % by != 0) {
        to += mod;
        if (to > (by + 1) * mod) {
            return -1;
        }
    }
    return (to / by) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    makeK;
    vector<int63> lengthes;
    bool fil = false;
    if (s[0] == s[s.size() - 1]) {
        fil = true;
    }
    char last = '-';
    fort(0, s.size()) {
        if (s[i] == last) {
            lengthes[lengthes.size() - 1]++;
        } else {
            last = s[i];
            lengthes.push_back(1);
        }
    }
    if (fil&&lengthes.size() > 1) {
        lengthes[0] += lengthes[lengthes.size() - 1];
        lengthes.pop_back();
    }
    int63 cngp1 = 0;
    fort(0, lengthes.size()) {
        cngp1 += lengthes[i] / 2;
    }
    cout << cngp1 * k << endl;
    return 0;
}
