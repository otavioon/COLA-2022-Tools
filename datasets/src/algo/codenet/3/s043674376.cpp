/*
オーダー
10**6	余裕を持って間に合う	
10**7	おそらく間に合う	余裕を持って間に合う
10**8	非常にシンプルな処理でない限り厳しい	おそらく間に合う
10**9		非常にシンプルな処理でない限り厳しい
logn	:OK
n		:10^7
nlogn	:10^6
n**2	:10^4
n**3	:300
2**n	:20
n!		:10



// 各桁の和を計算する関数
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

sort(a, a + N, greater<int>());  // a[0:N] を大きい順にソート

int num[110] = {0};  // バケット
for (int i = 0; i < N; ++i) {
    num[d[i]]++;  // d[i] が 1 個増える
}

map<string, int> mp; // 連想配列 map<キー型, 値型> オブジェクト名
for (int i = 0; i < N; ++i) {
    auto itr = mp.find(s[i]);        // s[i] が設定されているか？
    if(itr != mp.end() ) {
         mp[s[i]] += 1;
    }
    else {
         mp[s[i]] += 1 ;
    }
}
stack<int> s;	//intをデータとするスタックを用意
s.push(1);		//{} -> {1}
printf("%d\n", s.top());	// 3
s.pop();

queue<int> que;	//intをデータとするキューを用意
que.push(1);		//{} -> {1}
printf("%d\n", que.front());	// 1
que.pop();
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

// #define for(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18
// int 
// // 各桁の和を計算する関数
// int findSumOfDigits(int n) {
//   int amari = 0;
//   int keta = 0;
//   while (n > 0) { // n が 0 になるまで
//     amari += n % 2;
//     if (keta%2==0)
//     n /= 10;
//   }
//   return sum;
// }
 
 

int main() {
	// 入力
	ll N;
	cin >> N;
	ll A[N], B[N], C[N];
	for (ll i = 0; i < N; ++i) cin >> A[i];
	for (ll i = 0; i < N; ++i) cin >> B[i];
	for (ll i = 0; i < N; ++i) cin >> C[i];
 
	// 解法
	sort(A, A + N);
	sort(B, B + N);
	sort(C, C + N);
	// sort(C, C + N, greater<ll>());
	
	ll ans = 0;
	ll c = 0;
	ll a = 0;
	
	for (ll b = 0; b < N; ++b){
		while(C[c]<=B[b] & c<N){
			c++;
		}while(B[b]>A[a] & a<N){
			a++;
		}
		// printf("idx %lld %lld %lld\n", c,b,a);
		// printf("%lld %lld %lld\n", C[c],B[b],A[a]);
		ll plus = (a)*(N-c);
		// printf("+ %lld\n", plus);
		ans += plus;	
	}
	
	//出力
	cout << ans << endl;
}
