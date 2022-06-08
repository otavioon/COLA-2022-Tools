#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    multiset<int> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.insert(a);
    }
    int ans = 0;
    while (!nums.empty())
    {
        int biggest = *--nums.end();
        nums.erase(--nums.end());
        int two = 1 << 30;
        while ((two >> 1) > biggest)
            two >>= 1;
        if (nums.find(two - biggest) != nums.end())
        {
            ans++;
            nums.erase(nums.find(two - biggest));
        }
    }
    cout << ans << endl;
    return 0;
}
