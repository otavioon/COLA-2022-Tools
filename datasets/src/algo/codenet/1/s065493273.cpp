#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf = 1e9;

int N,Y;
int c[3][3];
int main(){
    REP(i,0,3){
        REP(j,0,3){
            cin>>c[i][j];
        }
    }

    if ( c[0][0] + c[2][2] == c[0][2] + c[2][0] &&
         c[1][1] + c[2][2] == c[1][2] + c[2][1] &&
         c[0][0] + c[1][1] == c[0][1] + c[1][0]
            ) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    return 0;
}