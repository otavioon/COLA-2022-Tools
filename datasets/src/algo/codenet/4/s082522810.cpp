#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
#define yes(j) std::cout << (j ? "yes" : "no") << endl;

int main(void)
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    REP(i, k)
    {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    while (n)
    {
        int tmp = n;
        bool flag = true;
        while (tmp > 0)
        {
            int a;
            a = tmp % 10;
            tmp /= 10;
            if (st.find(a) != st.end())
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << n << endl;
            return 0;
        }
        n++;
    }
}