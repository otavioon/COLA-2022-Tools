#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n ,a[101] ,b[101] , c[101] , ans;
int main()
{
   cin >>n;
   for (int  i = 0 ; i < n - 1 ;i++)
    cin >> a[i] ;
    if (n == 2)
    {
        cout << a[0] * 2 ;
        return 0 ;
    }
    ans = a[0] * 2 ;
  for (int  i = 1 ; i < n - 1 ;i++)
    {
        ans += min(a[i] ,a[i + 1]);
        //cout << ans <<endl;
    }
    //cout <<ans <<endl;
    cout <<ans + a[ n - 2];
    return 0;
}
