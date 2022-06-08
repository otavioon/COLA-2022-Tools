#include <iostream>
#include <set>

using namespace std;

multiset < int > s;

int bs(int val) {
    int pas = 16, r(-1);
    while (pas) {
        if (r + pas < 30 && (1<<(r + pas)) <= val)
            r += pas;
        pas >>= 1;
    }
    return (1<<(r + 1));
}

int main()
{
    int n, val, ans(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> val, s.insert(val);
    while (s.size()) {
        int x = bs(*s.rbegin()) - *s.rbegin();
        s.erase(*s.rbegin());
        if (s.find(x) != s.end())
            s.erase(x), ++ans;
    }
    cout << ans;
    return 0;
}
