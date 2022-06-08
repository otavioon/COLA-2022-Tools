#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define B       (cout << "Sehen Sie mich!" << endl)
#define VB(val) (cout << val << endl)

inline int ctoi(const char c){
        if('0' <= c && c <= '9') return (c -'0');
        return -1;
}

int main()
{
        int n;
        cin >> n;
        int a[n], b[n], c[n];
        for (int i = 0; i < n; i++)
                cin >> a[i];
        for (int i = 0; i < n; i++)
                cin >> b[i];
        for (int i = 0; i < n; i++)
                cin >> c[i];
        int ret = 0;

        int i = 0, j = 0, k = 0;
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        if (a[i] >= b[j])
                                continue;
                        for (k = 0; k < n; k++) {
                                if (b[j] >= c[k])
                                        continue;
                                ret++;
                        }
                }
        }
        VB(ret);
}