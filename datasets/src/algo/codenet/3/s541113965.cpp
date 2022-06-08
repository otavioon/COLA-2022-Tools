#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005], b[100005], c[100005];

int main()
{

   // freopen("input.c","r",stdin);
    while(cin >> n)
    {
            int i;
            for (i = 0; i < n; i++) cin >> a[i];
            for (i = 0; i < n; i++) cin >> b[i];
            for (i = 0; i < n; i++) cin >> c[i];
            sort(a, a + n);
            sort(b, b + n);
            sort(c, c + n);

            int cnt = 0;

            int j,k;

            for (i = 0 ; i < n; i++)
                for (j = 0; j < n; j++)
                {
                    for (k = 0; k < n; k++)
                    {
                        if (a[i]<b[j] && b[j]<c[k])
                            break;
                    }
                    cnt += (n - k);


                }

            cout<<cnt<<endl;

    }

    return 0;
}
