// https://atcoder.jp/contests/abc118/tasks/abc118_c

// http://ctylim.hatenablog.com/entry/2015/08/30/191553
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>

#define ALL(a) (a).begin(), (a).end()
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define MAXINDEX(c) distance((c).begin(), max_element((c).begin(), (c).end()))
#define MININDEX(c) distance((c).begin(), min_element((c).begin(), (c).end()))
#define DEBUG(x) std::cerr << #x << " = " << (x) << " (" << __FILE__ << "::" << __LINE__ << ")" << std::endl;
#define ERROR(s) std::cerr << "Error::" << __FILE__ << "::" << __LINE__ << "::" << __FUNCTION__ << "::" << (s) << std::endl;
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)

#define repd(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

template <typename T>
T inputValue(){
  T a;
  std::cin >> a;
  // scanf("%llu", &a);
  return a;
}

void inputArray(int *p, int a){
  rep(i, a){
    std::cin >> p[i];
    // scanf("%d",p+i);
  }
}

template <typename T>
void inputVector(std::vector<T> *p, int a){
  rep(i, a){
    T input;
    std::cin >> input;
    // scanf("%llu", &input);
    p->push_back(input);
  }
}

template <typename T>
void output(T a, int precision){
  if (precision > 0){
    std::cout << std::setprecision(precision) << a << "\n";
  }else{
    std::cout << a << "\n";
  }
}

void print() { std::cout << std::endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail){
  std::cout << head << ",";
  print(std::forward<Tail>(tail)...);
}

using namespace std;


const bool check(vector<int64_t> &h, int64_t A, int64_t B, int64_t n){
  // A*k + B*(n-k) >= h[0]
  // (A-B)*k >= h[0] - B*n
  // k = ( h[0] - B*n + (A-B) -1 ) / (A-B)
  int64_t sum = 0;
  EACH(v, h) {
    int64_t k = ( *v - B*n + (A-B) -1 ) / (A-B);
    // cout <<"***" << k << endl;
    sum += k;
    if(sum>n){
      return false;
    }
  } 
  return true;
}

int main(int argc, char **argv)
{
  int64_t N, A, B;
  scanf("%lld%lld%lld",&N, &A, &B);
  // print(N, A, B);
  vector<int64_t> h(N);
  FOR(i,0,N){
    scanf("%lld", &h[i]);
  }
  RSORT(h);
  // EACH(i,h){
    // print(*i);
  // }
  // print(check(h,A,B,1));
  // print(check(h,A,B,2));
  // print(check(h,A,B,3));
  // print(check(h,A,B,4));


  int64_t s = h[0]/A , t = h[0]/B;
  int64_t c = -1;
  bool b;
  while(s <= t){
    c = (s+t)/2;
    b = check(h,A,B,c);
    print(s,c,t,b);
    if(b==true){
      t = c-1;
    }else {
      s = c+1;
    }
  }

  c = b ? c : c+1;
  cout << c << endl;


  return 0;
}
