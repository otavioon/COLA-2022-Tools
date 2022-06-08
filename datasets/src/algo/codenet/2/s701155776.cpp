#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 2e5 + 3;
int N;
int A[MC];

int main(){
	cin >> N;
	repp(i,0,N) cin >> A[i];
	sort(A,A+N);
	int ans = 0;
	int k = N-1;
	repm(t,30,0){
		int i = 0;
		while(k >= 0 && A[k] >= (1<<(t-1))){
			if(A[k] < 0){
				--k;
				continue;
			}
			while(i < k && (A[k] + A[i] < (1<<t) || A[i] < 0)) ++i;
			if(i < k && A[k] + A[i] == (1<<t)){
				A[i] = A[k] = -1;
				++i;
				++ans;
			}
			--k;
		}
	}
	cout << ans << endl;
	return 0;
}
