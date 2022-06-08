#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const double pi=3.14159265358979323846;
int ctoi(const char c) {
    if ('0' <= c && c <= '9') return (c - '0');
    return -1;
}
vector<int> input(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    return vec;
}
void output(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return;
}
vector<vector<int>> input(int n, int m) {
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table. at(i).at(j);
        }
    }
    return table;
}
void output(vector<vector<int>> table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.at(0).size(); j++) {
            cout << table.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
long long perm(int n, int r) {
    if (n < r) {
        cout << "error" << endl;
        return 0;
    }
    long long perm = 1;
    for (int i = n; i > n - r; i--) {
        perm *= i;
    }
    return perm;
}
long long comb(int n, int r) {
    if (n < r) {
        cout << "error" << endl;
        return 0;
    }
    long long comb = perm(n,r);
    for (int i = r; i > 0; i--) {
        comb /= i;
    }
    return comb;
}
long long homo(int n, int r) {
    return comb(n + r - 1, n - 1);
}
long long fact(int n) {
    long long fact = 1;
    for (int i = n; i > 0; i--) {
        fact *= i;
    }
    return fact;
}
int gcd(int a, int b){
    if (a % b == 0){
        return(b);
    }else{
        return(gcd(b, a % b));
    }
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
bool isprime(int n){
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
vector<long long> divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;

    /*long long N;
    cin >> N;
    vector<long long> res = divisors(N);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;*/
}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
void sayYes(bool f) {
    if (f) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
void sayYES(bool f) {
    if (f) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> b=input(n-1);
  int ans=b[0]+b[n-2];
  for(int i=1;i<n-1;++i){
    ans+=min(b[i-1],b[i]);
  }
  cout << ans << endl;
}