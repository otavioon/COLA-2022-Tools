#include<bits/stdc++.h>
#define  ll long long
using namespace std;

int main()
{
    string str;
    ll k,n;
    cin>>str>>k;

    n = str.length();

    ll flg = 0;
    for(ll i=1;i<n;i++)
    {
        if(str[i] != str[i-1])
        {
            flg = 1;
            break;
        }
    }

    ll cnt1 = 0;
    ll i=0;
    while(i<n)
    {
        ll j = i+1;
        while(j<n && str[j] == str[i])
        {
            j++;
        }
        cnt1 += (j-i)/2;
        i = j;
    }


    if(flg == 0)
    {
        cout<<(k*n)/2;
    }
    else
    {

        if(str[0] == str[n-1])
        {
            ll i=0;
            ll j=n-1;
            while(str[i] == str[0]) i++;
            while(str[j] == str[0]) j--;
            ll cnt = (i+(n-1-j))/2;
            cnt = cnt*(k-1);

            ll cnt1 = 0;
            ll k = j+1;
            while(i<k)
            {
                ll j = i+1;
                while(j<k && str[j] == str[i])
                {
                    j++;
                }
                cnt1 += (j-i)/2;
                i = j;
            }
            cnt += cnt1*k;
            cout<<cnt;
        }
        else
        {
            cout<<(k*cnt1);
        }
    }

    return 0;
}
