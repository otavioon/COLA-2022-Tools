#include<bits/stdc++.h>
using namespace std ;
#define rep(i,a,n) for(int i =a;i<n;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
	ios;
    int n,s=0;
	cin>>n;
	int a[n],b[n],c[n-1];
	rep(i,0,n)
	{cin>>a[i];
	}
	rep(i,0,n)
	{cin>>b[i];
	s+=b[i];
	}
	rep(i,0,n-1)
	{cin>>c[i];
	}
    if(a[n-1]!=n)
    {s=s-c[a[n-1]-1];
	}
    for(int i=n-1;i>=0;i--)
    {if(a[n]=a[n-1]+1)
    {s+=c[a[n-1]-1];
	}
	}
	cout<<s<<endl;
	return 0;
}