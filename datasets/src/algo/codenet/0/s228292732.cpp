#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string str;
    ll n,k;

    cin>>str>>k;
    n = str.length();

    ll flg = 0;
    for(ll i=0;i<n;i++)
    {
        if(str[i] != str[0])
        {
            flg = 1;
            break;
        }
    }

    if(flg == 0)
    {
        cout<<(k*n)/2;
    }
    else
    {
        ll i=0;
        ll c1 = 0;
        while(i<n && str[i] == str[0])  i++;
        c1 = i;

        ll c2 = 0;
        ll j = n-1;
        while(j>=0 && str[j] == str[n-1])   j--;
        c2 = (n-1-j);

        ll ans = 0;

        if(str[0] == str[n-1])
            ans += c1/2 + c2/2 + ((c1+c2)/2)*(k-1);
        else
            ans += (c1/2 + c2/2)*k;

        while(i<=j)
        {
            ll k1=i+1;
            while(k1<=j && str[k1] == str[i]) k1++;
            ans += k*((k1-i)/2);
            i = k1;
        }
        cout<<ans;
    }
  
    return 0;
}