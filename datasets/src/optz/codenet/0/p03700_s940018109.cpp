#include <iostream>
#include <stdio.h>
using namespace std;
 
typedef long long LL;
const int MAX_N = 1e5 + 6;
 
LL a[MAX_N];
 
int main() {
	LL n,A,B;
	scanf("%lld %lld %lld",&n,&A,&B);
	for (int i=1;n>=i;i++) {
		scanf("%lld",&a[i]);
	}
	LL L=0,R=1e9+7;   //R is the answer
	while (R-L!=1) {
		LL mid=(L+R)>>1;
		LL need_A = 0;
		for (int i=1;n>=i;i++) {
			if (A*mid < a[i]) {
				need_A += mid+1;
			}
			else if (B*mid >= a[i]) {
				need_A += 0;
			}
			else {
				need_A += (a[i]-B*mid + (A-B-1))/(A-B);
			}
		}
		if (need_A <= mid) R=mid;
		else L=mid;
	}
	printf("%lld\n",R);
	return 0;
}