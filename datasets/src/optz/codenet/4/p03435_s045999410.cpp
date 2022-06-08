#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main()
{
	vector<vector<int> >C = vector<vector<int> >(3, vector<int>(3, 0));
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
		{
			int t;
			cin >> t;
			C[i][j] = t;
		}
	vector<tuple<int, int, int> > L;
	set<int> r;
	L.push_back(make_tuple(0, 11, 22));
	L.push_back(make_tuple(0, 21, 12));
	L.push_back(make_tuple(10, 1, 22));
	L.push_back(make_tuple(10, 21, 2));
	L.push_back(make_tuple(20, 11, 2));
	L.push_back(make_tuple(20, 1, 12));
	for (tuple<int, int, int> a : L)
	{
		int x= get<0>(a), y= get<1>(a), z= get<2>(a);
		r.insert(C[x/10][x%10]+C[y/10][y%10]+C[z/10][z%10]);
	}
	puts(r.size() == 1 ? "Yes" : "No");
}
