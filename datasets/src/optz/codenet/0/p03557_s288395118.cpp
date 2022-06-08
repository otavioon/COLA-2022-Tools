#include<iostream>
#include<string>
#include<cmath>
//#include<array>
#include<algorithm>
//#include<deque>
#include<vector>
//#include<utility>
//#include<set>
//#include<map>
//#include<list>

using namespace std;
using LLI = long long int;
vector<int>dir_x = { 0,0,1,1,1,-1,-1,-1 };
vector<int>dir_y = { 1,-1,1,0,-1,1,0,-1 };
vector<int>dir_x2 = { 0,0,1,-1 };
vector<int>dir_y2 = { 1,-1,0,0 };

//class UnionFind {
//public:
//	vector<int>data;
//	UnionFind(int size) :data(size, -1) {};
//	bool unionset(int x, int y) {
//		x = root(x), y = root(y);
//		if (x != y) {
//			if (data[y] < data[x]) {
//				swap(x, y);
//			}
//			data[x] += data[y];
//			data[y] = x;
//		}
//		return x != y;
//	}
//	bool findset(int x, int y) {
//		return root(x) == root(y);
//	}
//	int root(int x) {
//		return data[x] < 0 ? x : data[x] = root(data[x]);
//	}
//	int size(int x) {
//		return -data[root(x)];
//	}
//};

//LLI gcd(LLI x, LLI y) {
//	LLI tmp, r;
//	if (x < y) {
//		tmp = x;
//		x = y;
//		y = tmp;
//	}
//	r = x % y;
//	while (r != 0) {
//		x = y;
//		y = r;
//		r = x % y;
//	}
//	return y;
//}
//LLI lcm(LLI x,LLI y) {
//	return x / gcd(x,y) * y;
//}

//long nCr(int n,int r) {
//	long ans = 1;
//	for (int i = n; i > n - r;i--) {
//		ans = ans * i;
//	}
//	for (int i = 1; i < r + 1;i++) {
//		ans = ans / i;
//	}
//	return ans;
//}

//const int n_max = 8;
//array<array<bool, n_max>, n_max>graph;
//int dfs(int v,int N,array<bool,n_max>visited) {
//	int ret = 0;
//	bool all_visited = true;
//	for (int i = 0; i < N;i++) {
//		if (visited[i] == false) {
//			all_visited = false;
//		}
//	}	
//	if (all_visited) {
//		return 1;
//	}
//	for (int i = 0; i < N;i++) {
//		if (graph[v][i] == false) {
//			continue;
//		}
//		if (visited[i] == true) {
//			continue;
//		}
//		visited[i] = true;
//		ret += dfs(i,N,visited);
//		visited[i] = false;
//	}
//	return ret;
//}

//vector<vector<int>>sub;
//int dfs(int id) {
//	if (sub[id].size() == 0) {
//		return 1;
//	}
//	int minP = (int)1e9;
//	int maxP = 0;
//	for (int i : sub[id]) {
//		int P = dfs(i);
//		minP = min(minP, P);
//		maxP = max(maxP, P);
//	}
//	return minP + maxP + 1;
//}

int main(void) {
	vector<LLI>A;
	vector<LLI>B;
	vector<LLI>C;
	LLI N,a,cnt = 0;
	cin >> N;
	for (int i = 0; i < N;i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		B.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		C.push_back(a);
	}

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	
	for (int i = 0; i < N;i++) {
		LLI Acnt = lower_bound(A.begin(),A.end(),B[i]) - A.begin();
		LLI Ccnt = C.end() - upper_bound(C.begin(),C.end(),B[i]);
		cnt += Acnt * Ccnt;
	}
	cout << cnt << endl;
}