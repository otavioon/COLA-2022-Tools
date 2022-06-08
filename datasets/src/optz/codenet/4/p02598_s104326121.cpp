#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<cmath>
#include <map>
#include <set>
#include <iostream>

using namespace std;
set<pair<double,int>> logs;

double cut(int k) {
	set<pair<double, int>> st = logs;
	for (int i = 0; i < min(k,5000000); i++) {
		//for (auto p : st) cout << p.first << " ";
		//cout << "\n";
		auto it = prev(st.end());
		double l = (*it).first;
		double r = (*it).second;
		pair<double, int> new_elem = { (l * r) / (double)(r + 1),r + 1 };
		st.erase(it);
		st.insert(new_elem);

	}
	//for (auto p : st) cout << p.first << " ";
	auto it = prev(st.end());
	return (*it).first;
	
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		double x; 
		cin >> x;
		logs.insert({ x,1 });
	}
	cout << int(ceil(cut(k)));

}

