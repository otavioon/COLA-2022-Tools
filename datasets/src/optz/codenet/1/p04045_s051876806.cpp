//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj
#include<bits/stdc++.h>
using namespace std;int tc = 1;
#define happy ios::sync_with_stdio(false);
#define coding  cin.tie(0);
#define mp make_pair
#define ll long long
#define Pi atan(1)*4
#define pb  push_back
#define vpr vector<pr> 
#define pr pair<int, int> 
#define vi std::vector<int>
#define vll std::vector<ll>
#define YES printf("YES\n");
#define NO printf("NO\n");
#define Yes printf("Yes\n");
#define No printf("No\n");
#define all(n) n.begin(),n.end()
#define point(x) setprecision(x)
#define Test printf("Case %d: ",tc++);
#define Unique(c) (c).resize(unique(all(c))-(c).begin())

const int M = 1e9 + 7;
const ll  Inf = (ll)2e18 + 5;
const int N   = 2e5 + 5;

int solve() 
{
	//happy coding

	int n,k;
	cin>>n>>k;
	string s = to_string(n);
	int a[n+1];
	std::map<int, int> m;
	for(int i=0;i<k;i++){
		cin>>a[i];
		m[a[i]] = 1;
	}

	for(int i=0;s[i];i++){
		if(m[s[i]-'0']==0){
			cout<<s[i];
		}else{
			for(int j=(int)(s[i]-'0');j<10;j++){
				if(m[j]==0){
					cout<<j;
					break;
				}
			}
		}
	}cout<<endl;

	for(int i=1;i<=9;i++){
		if(m[i]==0){
			cout<<i;
			break;
		}
	}
	if(m[0]){

	}


	
	return 0;
}
int main(){
	int test = 1;
	//scanf("%d", &test);
	while (test--)solve();return 0;
}