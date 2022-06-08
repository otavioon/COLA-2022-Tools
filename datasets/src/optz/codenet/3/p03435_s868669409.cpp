#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int c[3][3];
  REP(i, 3) {
    REP(j, 3) {
      cin >> c[i][j];
    }
  }

  bool ch = true;
  while(ch) {
    REP(i, 3) {
      REP(j, 3) {
        if(c[i][j] < 2) {
          ch = false;
        } 
      }
    }

    if(ch) {
      REP(i, 3) {
        REP(j, 3) {
          c[i][j] -= 2;
        }
      }
    }
  }

  vector<int> a(3);
  vector<int> b(3);
  a[0]=-1, a[1]=-1, a[2]=-1;
  b[0]=-1, b[1]=-1, b[2]=-1;

  bool br = false;
  
  REP(i, 3) {
    REP(j, 3) {
      if(c[i][j] == 0) {
        a[i] = 0;
        b[j] = 0;
        a[(i+1)%3] = c[(i+1)%3][j];
        a[(i+2)%3] = c[(i+2)%3][j];
        b[(j+1)%3] = c[i][(j+1)%3];
        b[(j+2)%3] = c[i][(j+2)%3];
        br = true;
        break;
      }
    }
    if(br) break;
  }

  //REP(i, 3) cout << a[i] << endl;
  //REP(i, 3) cout << b[i] << endl;

  if(a[0] != -1) {
    REP(i, 3) {
      REP(j, 3) {
        if(a[i] + b[j] != c[i][j]) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
    cout << "Yes" << endl;
    return 0;
  }
  
  vector<int> a2(3);
  vector<int> b2(3);
  a2[0]=-1, a2[1]=-1, a2[2]=-1;
  b2[0]=-1, b2[1]=-1, b2[2]=-1;

  REP(i, 3) {
    REP(j, 3) {
      if(c[i][j] == 1) {
        a[i] = 1;
        b[j] = 0;
        a[(i+1)%3] = c[(i+1)%3][j];
        a[(i+2)%3] = c[(i+2)%3][j];
        b[(j+1)%3] = c[i][(j+1)%3]-1;
        b[(j+2)%3] = c[i][(j+2)%3]-1;
        a2[i] = 0;
        b2[j] = 1;
        a2[(i+1)%3] = c[(i+1)%3][j]-1;
        a2[(i+2)%3] = c[(i+2)%3][j]-1;
        b2[(j+1)%3] = c[i][(j+1)%3];
        b2[(j+2)%3] = c[i][(j+2)%3];        
      }
    }
  }

  br = false;
  REP (i, 3) {
    REP(j, 3) {
      if(c[i][j] != a[i] + b[j]) {
        br = true;
        break;
      }
    }
    if(br) break;
  }

  if(!br) {
    cout << "Yes" << endl;
    return 0;
  }

  br = false;
  REP(i, 3) {
    REP(j, 3) {
      if(c[i][j] != a2[i] + b2[j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;

}
