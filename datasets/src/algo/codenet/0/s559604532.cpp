#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long k,sum=0;
    while(cin>>s>>k)
    {
        sum=0;
        int len=0;
        len=s.size();
        for(int i=0;i<len-1;i++)
        {
            if(s[i]==s[i+1])
            {
                sum+=1;
                i++;
            }
        }
        long long  temp=0;
        if(len>2)
        {
            if(s[0]==s[len-1])
            {
                if(s[len-1]!=s[len-2])
                {
                    temp=k-1;
                    //cout<<"sum="<<sum<<endl;
                }
            }
        }
        //cout<<"sum="<<sum<<endl;
        if(len==1)
        {
            cout<<k/2<<endl;
        }
        else
          cout<<(sum*k)+temp<<endl;
    }
    return 0;
}
