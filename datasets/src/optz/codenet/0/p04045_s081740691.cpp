#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    int n, k, x;
    cin >> n >> k;
    bool a[10] = {};
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        a[x] = true;
    }

    int ans;
    for (int i = n;; i++)
    {
        string s = to_string(i);
        bool flag = true;
        for (int j = 0; j < s.length() && flag; j++)
        {
            for (int k = 0; k < 10 && flag; k++)
            {
                if (a[k] == true && s[j] == k + '0')
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}
