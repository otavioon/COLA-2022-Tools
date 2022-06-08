#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long k,sum1=0,sum2=0,sum3=0;
    while(cin>>s>>k)
    {
        sum1=0;
        sum2=0;
        sum3=0;
        int len=0;
        len=s.size();
        for(int i=0;i<len-1;i++)
        {
            if(s[i]==s[i+1])
            {
                sum1+=1;
                i++;
            }
        }
        s+=s;
        for(int i=0;i<(len*2)-1;i++)
        {
            if(s[i]==s[i+1])
            {
                sum2+=1;
                i++;
            }
        }
        s+=s;
         for(int i=0;i<(len*3)-1;i++)
        {
            if(s[i]==s[i+1])
            {
                sum3+=1;
                i++;
            }
        }


    // cout<<"sum1="<<sum1<<"  sum2="<<sum2<<" sum3="<<sum3<<endl;
      long long total=0;
      sum3=sum2-sum1;
      sum2-=sum1;

      if(k==1)
      {
          cout<<sum1<<endl;
      }
      else
      {
            total+=sum1;
            total+=(k/2)*sum2;
            if(k%2==0)
            {
                total+=((k/2)-1)*sum3;
            }
            else
            {
                total+=(k/2)*sum3;
            }
            cout<<total<<endl;

      }



    }
    return 0;
}
