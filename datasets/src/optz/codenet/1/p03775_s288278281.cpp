#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define FOR(i,a,b) for(int i=(a); i<int(b); ++i)
#define RFOR(i,a,b) for(int i=(b)-1; i>=int(a); --i)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,int(n)+1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
#define al(d) d.begin(),d.end()

template <typename T>
void putv(vector<T>& V){
	// cout << "The elements in the vector are: " << endl;
	for(auto x: V)
		cout << x << " ";
	cout << endl;
}
template <class T>
vector<T> getv(int n){
	vector<T> vec;
	rep(i,n){
		T input;
		cin >> input;
		vec.emplace_back(input);
	}
	return vec;
}
int digit(unsigned long long n);
int main(){
	long long N;
cout << N << endl;
	long long sqrt = (long long)pow(N,0.5);
	for(long long i=sqrt; i>0; --i)
		if(N%i==0){
			cout << digit(N/i) << endl;
			break;
		}
	return 0;
}

int digit(unsigned long long n){
	if(n == 0) return 1;
	unsigned int cntr = 0;
	while(n!=0){
		n /= 10;
		cntr++;
	}
	return cntr;
}