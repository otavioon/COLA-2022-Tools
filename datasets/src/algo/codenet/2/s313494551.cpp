#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

long n;
std::multiset<long> st;
long ans;

int main(){
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		long a;
		scanf("%ld", &a);
		st.insert(a);
	}
	while(st.size()){
		auto it1 = st.end();
		it1--;
		long a = *it1;
		st.erase(it1);
		long sum = 1;
		while(sum <= a){
			sum *= 2;
		}
		long b = sum - a;
		auto it = st.find(b);
		if(it != st.end()){
			st.erase(it);
			ans++;
		}
	}
	printf("%ld\n", ans);
	return 0;
}
		
