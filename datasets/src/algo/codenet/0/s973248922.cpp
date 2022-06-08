#include <bits/stdc++.h>

using namespace std;
string str;
int main( )
{
    long long k;
    cin>>str>>k;
    long long num=1;
    long long len=str.length();
    long long sum=0;
    bool flag=0;
    if(len==1)
    {
        cout<<k/2<<endl;
    }
    else
    {
        for(long long i=1; i<len; ++i)
        {
            if(str[i-1]==str[i])
            {
                ++num;
            }
            else
            {
                sum+=(num/2);
                num=1;
            }
        }
        sum+=(num/2);
        if(str[0]==str[len-1]&&str[len-2]!=str[len-1])
        {
            sum++;
            flag=1;
        }
        if(flag)
            cout<<sum*k-1<<endl;
        else
            cout<<sum*k<<endl;
    }
    return 0;
}

