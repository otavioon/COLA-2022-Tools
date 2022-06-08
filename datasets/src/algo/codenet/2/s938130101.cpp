#include<iostream>
#include<algorithm>
#define D(x) cout<<"D:"<<#x<<'='<<x<<endl;
using namespace std;
typedef long long ll;
inline int nextint(void)
{
	int k;
	cin>>k;
	return k;
}
int w[200005];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = nextint(), cnt = 0;
	for(int i = 0; i < n; i++) cin>>w[i];
	sort(w, w+n);
	for(ll i = 2; i <= 1<<20; i<<=1)
	{
		int l = 0, r = n-1;
		while(l < r)
		{
			if (w[l]+w[r] > i) r--;
			else if (w[l]+w[r] < i) l++;
			else cnt++, l++, r--;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
