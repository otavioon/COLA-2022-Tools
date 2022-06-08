#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main(){
	int n;
	cin >> n;
	ll a[n],b[n],c[n];
	FOR(i,n){
		cin >>a[i];
	}
	FOR(i,n){
		cin >> b[i];
	}
	FOR(i,n){
		cin >> c[i];
	}
	ll sum=0;
	int i=0,j=0,k=0;
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	while(i<n){
		while(j<n && b[j]<=a[i]) j++; //find correct middle size
		while(k<n && c[k]<=b[j])k++;
		int l=j;
		int l1=k;
		while(l<n){
			while(l1<n && c[l1]<=b[l])l1++;
			sum+=(n-l1);
			l++;
		}
		i++;
	}
	cout << sum;
	return 0;
}