#include <array>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define PB push


#define MOD 1000000007LL
#define EPS 1e-10

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return(false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return(true);
  }

  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }

  int size(int k)
  {
    return(-data[find(k)]);
  }

  bool same(int x, int y)
  {
      return find(x) == find(y);
  }
};

int main()
{
    vector<vector<int> > c(3);
    REP(i, 3) c[i].resize(3);
    REP(i, 3) REP(j, 3) cin >> c[i][j];
    for (int a1 = 0; a1 <= 100; ++a1)
    {
        int b[3] = {c[0][0] - a1, c[0][1] - a1, c[0][2] - a1};
        int a[3] = {c[0][0] - b[0], c[1][0] - b[0], c[2][0] - b[0]};
        bool ok = true;
        REP(i, 3)
        {
            REP(j, 3)
            {
                if (c[i][j] != (a[i] + b[j]))
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
            {
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
