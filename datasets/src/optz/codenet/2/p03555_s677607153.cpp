#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

#define all(c) c.begin(),c.end()
#define repeat(i,n) for(int i=0;i<static_cast<int>(n);i++)
#define debug(x) #x << "=" << (x)
#define dump(x) cerr << debug(x) << " (L:" << __LINE__ << ")"<< endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i] << ",";
    }
    os << "]";
    return os;
}

template<typename T>
T input(){
    T t;
    cin >> t;
    return t;
}

template<typename T>
vector<T> input(const int N){
    vector<T> v(N);
    repeat(i,N) cin >> v[i];
    return v;
}

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return (a / gcd(a, b)) * b;
}

long long mul(const long long& a, const long long& b, const long long& mod) {
    return ((a % mod) * (b % mod)) % mod;
}

long long power(const long long& x, const long long& y, const long long& mod) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x % mod;
    } else {
        long long value = power(x, y / 2, mod);
        if (y % 2 == 0) {
            return mul(value, value, mod);
        } else {
            return mul(value, value, mod) * x % mod;
        }
    }
}

long long div(const long long& a, const long long& b, const long long& mod) {
    return mul(a, power(b, mod - 2, mod), mod);
}

map<long long, long long> factorials;
long long factorial(const long long& n, const long long& mod) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (factorials[n] != 0) {
        return factorials[n];
    }
    factorials[n] = n * factorial(n - 1, mod) % mod;
    return factorials[n] % mod;
}

long long combination(const long long& n, const long long& x, const long long& mod) {
    long long numerator = 1;
    long long denominator = 1;
    repeat(i, x) {
        numerator *= (n - i) % mod;
        numerator %= mod;
        denominator *= (i + 1) % mod;
        denominator %= mod;
    }
    return div(numerator, denominator, mod);
}

int main(){
    string first;
    string second;

    cin >> first;
    cin >> second;

    repeat (i, first.size()) {
        if (first[i] != second[second.size() - 1 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
