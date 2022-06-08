#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>

#define ll long long
#define vl vector<ll>
#define vvl vector< vector<ll> >
#define vb vector<bool>
#define vbb vector< vector<bool> >
#define vs vector<string>
#define vc vector<char>
#define vvc vector< vector<char> >

#define all(a) (a).begin(),(a).end()
using namespace std;

bool check(vs &ngo, string s){
	for (string t : ngo) if (t == s) return 0;
	return 1;
}

int main(){
	ll a, b; cin >> a >> b;
	cout << (a - 1)*(b - 1) << endl;
	return 0;
}