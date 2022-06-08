#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <stack>
#include <tuple>

using namespace std;
typedef long long ll;

int main()
{
    string n;int k;
    cin >> n >> k;
    set<char> d = { '0','1','2','3','4','5','6','7','8','9' };
    for (int i = 0; i < k; i++)
    {
        char num;
        cin >> num;
        d.erase(num);
    }
    for (auto& c : n)
    {
        cout << *(d.lower_bound(c));
    }
    cout << endl;
    return 0;
}