#include <bits/stdc++.h>

using namespace std;

struct P {
  int v, c, i;
};

struct comp
{
    bool operator()(const P &r, const P &l)
    {
        return r.v < l.v;
    }
};


P newP(int v, int c, int i) {
  P p;
  p.v = v;
  p.c = c;
  p.i = i;
  return p;
}

typedef long long ll;
const int mxn = 2e5;
int x,n, k;
set<P,comp> a;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  int temp;
  for (int i = 0;i<n;i++) {
    cin >> temp;
    a.insert(newP(temp, 0, temp));
  }

  while (k>0) {
    auto it = a.rend();
    int v = (*it).i - ((*it).i/(*it).c)*((*it).c-1);
    P p = newP(v, (*it).c+1,(*it).i);
    a.erase((*it));
    a.insert(p);
  }
  auto it = a.rend();
  cout << (*it).v <<endl;





}
