#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)	for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n)	for(int i=(s), i##_len=(n); i<i##_len; ++i)

#define ALL(obj)	(obj).begin(),(obj).end()

typedef unsigned int 			uint;
typedef unsigned long long int	ull;
typedef long long int 			ll;

typedef pair<int,int>			P;

#define LINF		((ll)1 << 63 -1)
#define INF 		(1<<29)
#define MINF		-2000000007
#define MAX 		205

const int MOD = 1e9+7;
// テンプレ終了
//====================================================================//

//
int main(){
	int suml=0;
	int ns = 0;
	REP(i,9){
		int a;
		cin>>a;
		if(i%4==0)ns+=a;
		suml+=a;
	}

	cout <<(suml%3==0 && ns*3==suml ? "Yes" : "No") << endl;



	return 0;
}


