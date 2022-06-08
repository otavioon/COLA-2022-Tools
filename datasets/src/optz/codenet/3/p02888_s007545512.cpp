#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    long long ans = 0;
    for(int i=0; i<n; ++i){
        int k = i + 2;
        for(int j=i+1; j<n; ++j){
            while(k < n && v[k] < v[i] + v[j])
                ++ k;
            ans += max(0, k - j - 1);
        }
    }
    cout << ans << endl;

    return 0;
}
