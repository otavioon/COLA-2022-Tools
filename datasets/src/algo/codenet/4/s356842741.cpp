#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

set<int> s;

bool isOk(int n)
{
    while (n > 0)
    {
        if(s.count(n % 10))
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0, x; i < k; i++)
    {
        cin >> x;
        s.insert(x);
    }
    while(1)
    {
        if(isOk(n))
            break;
        n++;
    }
    cout << n;
    return 0;
}