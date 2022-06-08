#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


ll calc(char s[], int l)
{
	ll ret=0;
	int c=1;
	for(int i=1;i<l;i++)
	{
		if(s[i]==s[i-1])
		{
			c++;
		}
		else
		{
			ret+=c/2;
			c=1;
		}
	}
	ret+=c/2;
	return ret;
}


int main(void)
{
	char s[200+2];
	int k;

	while(scanf("%100[a-z]\n%d\n", s, &k)==2)
	{
		int l=strlen(s);
		int is_loop=0;

		for(int i=0;i<l;i++) s[i+l]=s[i];

		int p=-1;
		for(int i=0;i<l;i++)
		{
			if(s[l+i]!=s[l+i-1])
			{
				p=i;
				break;
			}
		}
		ll ans=(ll)l*k/2;
		if(p>=0) ans=calc(s, l)+calc(s+p, l)*(k-1);

		printf("%lld\n", ans);
	}
	return 0;
}
