/*
对应原理
其实每次只有两种选择，所有这个题的对拍很好写
怎么确定能不能达到最大值呢
跑步的速度是可以加快的，每次贪心选择能行吗
有一些能够拿两次，最终答案一定是要将什么拿两次的

最快的办法当然是永不回头，但是最慢的办法并不是一步一回头
我们要积累7+7+1=15
顺时针能够拿两次
为了把很大的一个数拿两次，必须他的补集中有能够回去的，并且那个数字一定是我右边紧邻的那个
为了拿到这一个7两次，顺时针必须留一个，
就意味着逆时针3次对应顺时针1次
并且必须先逆3
为了拿到这个4两次，顺时针留一个
则逆2顺2 且逆先
为了拿到3两次，顺时针留一个
逆1顺3

i n-i
当i<n-i时
左i 右(i+1)减去最左边 最后一次是顺时针 a[1...i]*2+((i+1)*2*n-a[i+1...i+i+1]*2)-(n-a[i+1])
左i减去最右边 右i 最后一次是逆时针     a[1...i]*2+(i*2*n-a[i+1...i+i]*2)-a[i]

i=n-i时
左i右i 减去左或减去右   a[1...i]*2+(i*2*n-a[i+1...i+i]*2)-a[i]/a[1...i]*2+(i*2*n-a[i+1...i+i]*2)-a[i+1]
i>n-i时
左n-i+1减去最右边 右n-i
左n-i，右n-i减去最左边
*/
#include<bits/stdc++.h>
#define MAXN 200005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long ll;
const ll INF=1e18;
ll n,x,mypow[35],ans;
multiset<ll>ms;
void init()
{
    mypow[0]=1;
    for(ll i=1;i<=32;i++)
    {
        mypow[i]=mypow[i-1]*2;
    }
}
int main()
{
    init();
//    ms.insert(2);
//    ms.insert(2);
//    printf("%d",ms.find(2)==ms.begin());
//    freopen("c://duipai//939cdata.txt", "r", stdin);
//    freopen("c://duipai//939cwa.txt", "w", stdout);
    while(~scanf("%lld",&n))
    {
//        string str;
//        cin>>str;
//        cout<<str<<endl;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            ms.insert(x);
        }
        for(multiset<ll>::reverse_iterator it=ms.rbegin();it!=ms.rend();it++)
        {
            x=*it;
            ll p=upper_bound(mypow+1,mypow+1+32,x)-mypow;
            ll y=mypow[p]-x;
            multiset<ll>::iterator it1=ms.find(y);
            if(it1==ms.end())
            {
                continue;
            }
            multiset<ll>::iterator it2=(++it).base();
            if(it2!=it1)
            {
                ms.erase(it1);
                ans++;
            }
            it--;
        }
        printf("%lld\n",ans);
    }
}
/*
*/
