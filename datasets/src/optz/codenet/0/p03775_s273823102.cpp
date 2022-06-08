#include <bits/stdc++.h>//万能头文件
using namespace std;
typedef long long ll;//注意要开long long
namespace doit
{
    inline ll read()//快读函数
    {
        ll x=0,p=1;
        char c;
        c=getchar();
        while(c<'0'||c>'9')
        {
            if(c=='-')
                p=-1;
            c=getchar();
        }
        while(c>='0'&&c<='9')
        {
            x=x*10+c-'0';
            c=getchar();
        }
        return x*p;
    }
    inline int f(ll n)//求数的位数
    {
        int len=0;
        while(n)
        {
            n/=10;
            len++;
        }
        return len;
    }
    inline void put()
    {
        ll n,ans;
        n=read();
        for(register int i=sqrt(n);i>=1;i--)//从sqrt(N)开始找
            if(n%i==0)//如果找到了
            {
                ans=n/i;//就为最优解
                break;
            }
        std::cout<<f(ans)<<"\n";//输出位数就OK了
    }
}
int main()
{
    ios::sync_with_stdio(false);
    doit::put();
}