#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
const int INFTY = (1 << 21); // 2097152
// const ll INFTY = (1LL << 60);
const ll MD = 1000000007LL;
// fprintf(stderr, "%d %lld \n", x, xll);


int N;
int A[100000], B[100000], C[100000];

int main() {
	cin >> N;
	rep(i, N){ cin >> A[i]; }
	rep(i, N){ cin >> B[i]; }
	rep(i, N){ cin >> C[i]; }
	sort(&A[0], &A[N]);
	sort(&B[0], &B[N]);
	sort(&C[0], &C[N]);

	int a = -1;
	int c = 0;
	ll ret = 0;
	rep(b, N){
		while(true){
			if(a < N-1 && A[a+1] < B[b]) a++;
			else break;
		}
		while(true){
			if(c < N-1 && C[c] <= B[b]) c++;
			else break;
		}
		ret += (ll)(a+1) * (ll)(N-c);
        // fprintf(stderr, "b:%d, %d - %d * %d\n", b, B[b], (a+1), (N-c));
	}

	cout << ret << endl;
}