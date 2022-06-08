//do not think about past and stay in this moment
//organize and work - Abhinav IIITA
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define int long long
#define ld long double
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end() 
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod;
int Arr[100005];
void seive(){
		Arr[0]=Arr[1]=1;
		for(int i=2;i<100005;++i){
			if(Arr[i]==0)
			for(int j=2*i;j<100005;j+=i)
			Arr[j]=1;
		}
}


bool isprime(int a){
	if(a<2)
	return false;
	if(a==2)
	return true;
	if(a%2==0)
	return false;
	for(int i=3;i*i<=a;i+=2)
	if(a%i==0)
	return false;
	return true;
}




// -----------------------------------------------------------------------


// -----------------------------------------------------------------------



void q1(){
	int k,x;
	cin>>k>>x;
	int pp=500*k;
	if(pp>=x)
	cout<<"Yes";
	else
	cout<<"No";	
}
// -----------------------------------------------------------------------


void q2(){
	int a,b;
	cin>>a>>b;
	string s;cin>>s;
	if(s[a]!='-'){
		cout<<"No\n";
		return ;
	}
	for(int i=0;i<=a+b;++i){
		if(i==a)
		continue;
		if(!(s[i]>='0' && s[i]<='9')){
			cout<<"No\n";
			return ;
		}
	}
	cout<<"Yes\n";
}

// -----------------------------------------------------------------------

void q3(){
	int n;
	cin>>n;
	int c[n-1],s[n-1],f[n-1];
	for(int i=0;i<n-1;++i)
	cin>>c[i]>>s[i]>>f[i];
	int res[n];
	res[n-1]=0;
	for(int i=n-2;i>=0;--i){
		int t=s[i]+c[i];
		for(int j=i+1;j<n-1;++j){
			if(t<=s[j]){
				t=s[j];
				t+=c[j];
			}else{
				int next = (t+f[j]-1)/f[j];
				next*=f[j];
				t=next+c[j];
			}
		}
		res[i]=t;
	}
	for(int i=0;i<n;++i)
	cout<<res[i]<<endl;
}


// -----------------------------------------------------------------------

void q4(){
	seive();
	//cout<<Arr[23]<<endl;
	int ans[100005];
	ans[0]=0;ans[1]=0;ans[2]=0;
	for(int i=3;i<=100005;i+=2)
	{
		int num=i+1;
		num/=2;
		if(Arr[i]==0 && Arr[num]==0)
		ans[i]=1;
		else
		ans[i]=0;
	}
	//cout<<ans[3]<<endl;
	
	for(int i=1;i<100005;++i)
	ans[i]+=ans[i-1];
	//cout<<ans[7]<<endl;

	int q;cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<ans[r+1]-ans[l]<<endl;
		/*int cp=0;
		for(int i=l;i<=r;++i){
			int num=i+1;
			num/=2;
			if(i%2==1)
			if(isprime(i) && isprime(num))
			cp++;
		}
		cout<<cp<<endl;*/
	}
}

// -----------------------------------------------------------------------


int32_t main()
{
	mod=1e+7;
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 	
	int t=1;
	//cin>>t;
	while(t--)
	q1();
	return 0;
}
