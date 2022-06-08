#include<cstdio>
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<complex>
#include <cstring>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<limits>
#include<climits>
#include<cfloat>
#include<functional>
#include<iterator>
#include <random>
#define inf  1000000000
#define mod  1073741824
#pragma GCC optimization ("O3")
using namespace std;
const int N = 100*1000+5;
#define all(x) begin(x),end(x)
int main()
{
   
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
  	int n,k;
  	set<int>s;
  	cin >> n >> k;
  	for (int i = 0; i < k; ++i)
  	{
  		int a;
  		cin >> a;
  		s.insert(a);
  	}
  	while(true)
  	{
  		int m = n;
  		bool j = true;
  		while(m > 0){
  			if(s.count(m%10)){
  				j = false;
  			}
  			m /= 10;
  		}
  		if(j){
  			cout << n << endl;
  			break;
  		}
  		n++;
  	}
  	return 0;
}