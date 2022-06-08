#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
#define MAXN 200000
#define INF 2000000000
#define LL long long
int n,ans;
int a[MAXN+5];
map<int,int> Dic;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        Dic[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        LL p=1;bool F=0,K=0;
        if(Dic[a[i]]==0)continue;
        while(p<=INF)p*=2;
        while(!F&&p>1)
        {
            p/=2;
            if(p-a[i]>=0)
            {
                if(p-a[i]==a[i])K=1;
                else
                {if(Dic[p-a[i]]>=1)ans++,Dic[a[i]]--,Dic[p-a[i]]--,F=1;}
            }
        }
        if(!F&&K&&Dic[a[i]]>1)ans++,Dic[a[i]]-=2,F=1;
    }
    printf("%d",ans);
}
