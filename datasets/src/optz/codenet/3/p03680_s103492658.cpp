#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<random>
#include<math.h>
#include<limits.h>
#include<iterator>
#include<queue>
#include<functional>
#define rep(i,a) for(int i=0;i<a;i++)
#define nrep(i,a,b) for(int i=a;i<b;i++)
#define mrep(i,a) for(int i=a;i>=0;i--)
#define ll long long
#define vl vector<ll> 
#define vvl vector<vector<ll> > 
#define vb vector<bool> 
#define vvb vector<vector<bool> > 
#define INF 11234567890123456789
using namespace std;

void dfs(ll depth,ll index, vl &nextButton, vb &pushButton){
	if (index == 1){
		cout << depth << endl;
		exit(0);
	}if (pushButton[index]) return;
	pushButton[index] = true;
	dfs(depth + 1, nextButton[index], nextButton, pushButton);
}

int main(){
	ll n; cin >> n;
	vl nextButton(n); rep(i, n) cin >> nextButton[i];
	rep(i, n) nextButton[i]--;
	vb pushButton(n, false);
	dfs(0, 0, nextButton, pushButton);
	cout << -1 << endl;
	return 0;
}