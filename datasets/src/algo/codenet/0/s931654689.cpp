#include <bits/stdc++.h>
#define REP(i,n) for(int64_t i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REV(c) reverse((c).begin(),(c).end())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define COUTDOUBLE(d,i) cout << setprecision((i)) << (d) << endl;
#define VIN(v) for(int64_t i=0;i<(v).size();i++){cin >> (v).at(i);}
#define MREP(i,m) for(auto i=(m).begin(); i != (m).end(); ++i) // auto key = i->first;auto value = i->second;

using namespace std;
typedef int64_t I;
typedef pair<I,I> P;
typedef vector<I> V;

I MOD = pow(10,9)+7;
I MAX = LONG_MAX;
I MIN = LONG_MIN;

// 最大公約数
I gcd(I a, I b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
I lcm(I a, I b) {
  return a * b / gcd(a, b);
}

int ctoi(char c){
  return c - '0';
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  I k;
  cin >> s >> k;
  I t=0, now=0;
  string ss;
  char c;
  if (k < pow(10,5)){
    REP(i,k){
      ss += s;
    }
    REP(i,ss.size()){
      if (c == ss.at(i)){
        now++;
      }else{
        t += now / 2;
        now = 0;
        now++;
      }
      c = ss.at(i);
    }
    t += now / 2;
    cout << t << endl;
    return 0;
  }else{
    I ch = 0;
    I diff = 0;
    bool chk=false;
    I diffE, diffO;
    REP(i,10){
      t = 0;
      now=0;
      ss += s;
      REP(j,ss.size()){
        if (c == ss.at(j)){
          now++;
        }else{
          t += now / 2;
          now = 0;
          now++;
        }
        c = ss.at(j);
      }
      t += now / 2;
      //cout << t << " " << ch << " " << diff << endl;
      if ((t - ch) == diff){
        chk = true;
        diff = t - ch;
        ch = t;
      }else{
        diff = t - ch;
        ch = t;
      }
      if (i==8){
        diffO = diff;
      }else if (i==9){
        diffE = diff;
      }
    }
    I an = t + (diffE + diffO) * ((k - 10)/2);
    if (k % 2 == 1){
      an += diffO;
    }
    cout << an << endl;
    return 0;
  }
  return 0;
}

