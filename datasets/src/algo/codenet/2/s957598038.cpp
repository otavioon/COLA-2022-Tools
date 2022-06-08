#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
multiset <int> Set;
int n,res;
int main(){
	int i,a;
	scanf ("%d",&n);
	for (int i=0;i<n;i++){
		scanf ("%d",&a);
		Set.insert(a);
	}
	while (!Set.empty()){
		auto it=Set.end();
		it--;
		int x=*it;
		Set.erase(it);
		for (i=1;i<=x;i*=2);
		if (Set.find(i-x)!=Set.end()){
			Set.erase(Set.find(i-x));
			res++;
		}
	}
	printf ("%d",res);
	return 0;
}