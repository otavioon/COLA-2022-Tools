#include <bits/stdc++.h>

using namespace std;
string str;
int main( )
{
    long long k;
    cin>>str>>k;
    long long num=0;
    long long len=str.length();
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
                ++i;
            }
        }
        if(str[0]==str[len-1]&&str[len-2]!=str[len-1])
        {
            num++;
            flag=1;
        }
        if(flag)
            cout<<num*k-1<<endl;
        else
            cout<<num*k<<endl;
    }
    return 0;
}

