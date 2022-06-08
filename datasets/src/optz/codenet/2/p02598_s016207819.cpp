#include<bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
int isPos(vector<double> A, double L, int k) {
	int n = A.size(), count = 0;
	for(int i=0;i<n;i++) {
		count+=(A[i]-1)/L;
	}
	if(count==k) return 0;
	else if(count>k) return 1;
	else return -1;
}
int main() {
	int n,k;
	cin>>n>>k;
	vector<double> A(n);
	double L = 0, R = INT_MIN;
	for(double &i:A) {
		cin>>i;
		R = max(R,i);
	}
	if(k==0) {
		cout<<R;
		return 0;
	}
	double prospect = 0;
	while(L<=R) {
		double mid = L + (R-L)/2;
		int check = isPos(A,mid,k);
		if(check<0) {
			R = mid-1;
		} else if(check > 0) {
			L = mid+1;
		} else {
			prospect = mid;
			R = mid-1;
		}
	}
	//debug()<<imie((int)ceil(prospect));
	cout<<(int) ceil(prospect);
}

