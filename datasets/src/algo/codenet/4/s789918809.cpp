#include "bits/stdc++.h"
using namespace std;

//諸機能
#pragma region MACRO 
#define putans(x) cerr << "answer: " ; cout << (x) << endl
#define dputans(x) cerr << "answer: "; cout << setprecision(10) << (double)(x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define RREP(i,a,n) for(int i=(int)(n); i>= a; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) begin((a)),end((a))
#define mp make_pair
#define exist(container, n) ((container).find((n)) != (container).end())
#define substr(s,i,l) string((s), (i), (l))
#define tos(x) (to_string((x)))
#ifdef _DEBUG //ファイルからテストデータを読み込む
	std::ifstream ifs("data.txt");
	#define input ifs >>
#else 
	#define input cin >>
#endif
#pragma endregion
//デバッグなどの支援
#pragma region CODING_SUPPORT
#define dbg(var0) { std::cerr << ( #var0 ) << "=" << ( var0 ) << endl; }
#define dbg2(var0, var1) { std::cerr << ( #var0 ) << "=" << ( var0 ) << ", "; dbg(var1); }
#define dbg3(var0, var1, var2) { std::cerr << ( #var0 ) << "=" << ( var0 ) << ", "; dbg2(var1, var2); }
#define dbgArray(a,n) {std::cerr << (#a) << "=";  rep(i,n){std::cerr <<(a[i])<<",";} cerr<<endl;} 
#ifndef _DEBUG
#define dbg1 {}
#define dbg2 {}
#define dbg3 {}
#define dbgArray {}
#endif 
#pragma endregion 
//typedef（書き換える、書き足す可能性ある）
#pragma region TYPE_DEF
typedef long long ll; 
typedef pair<int,int> pii; typedef pair<string,string> pss;typedef pair<int,string>pis;typedef pair<string,int>psi;
typedef vector<string> vs; typedef vector<int> vi;
#pragma endregion
//諸々の定数(書き換える可能性ある)
#pragma region CONST_VAL
#define PI (2*acos(0.0))
#define EPS (1e-9)
#define MOD (int)(1e9 + 7)
#define INF (1e9)
#pragma endregion


int main()
{
	int n, k; input n >> k;
	int max = 100000;
	set<int> d;
	rep(i, k) {
		int di; input di;
		d.insert(di);
	}
	int tmp = n;
	while (true) {
		int judge = tmp;
		bool ok = true;
		while (judge != 0){
			dbg2(judge,judge - ( ( judge / 10 ) * 10 ));
			if (exist(d,judge - ((judge / 10)* 10))) {			
				ok = false;
				break;
			}
			judge /= 10;
		}
		if (ok){
			putans(tmp);
			break;
		}
		tmp++;
	}

	return 0;
}
