#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-6;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
char s[110];
ll k;
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%s",s+1);
    cin>>k;
    int len=strlen(s+1),Front=1,Back=1,j,hit=1;
    ll ans=0;
    bool flag=0;
    if(len==1){
        printf("%lld\n",k/2);
        return 0;
    }
    for(int i=2;i<=len;i++){
        if(flag==0 && s[i]==s[i-1]){
            flag=1;
            hit=2;
            if(i==len) ans+=hit/2;
        }
        else if(flag==0 && s[i]!=s[i-1]);
        else if(flag==1 && s[i]==s[i-1]){
            hit++;
            if(i==len) ans+=hit/2;
        }
        else if(flag==1 && s[i]!=s[i-1]){
            flag=0;
            ans+=hit/2;
            hit=1;
        }
        else;
    }
    ans*=k;
    //cout<<ans<<endl;
    if(s[1]==s[len]){
        for(j=2;s[j]==s[j-1];j++);
        Front=j-1;
        for(j=len-1;s[j]==s[j+1];j--);
        Back=len-j;
        //printf("Front=%d\n",Front);
        //printf("Back=%d\n",Back);
        ans-=((Front/2)*(k-1));
        ans-=((Back/2)*(k-1));
        ans+=((Front+Back)/2*(k-1));
    }
    cout<<ans<<endl;
	return 0;
}
