//Rochy'.'
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define fl(i,a,b) for(int i=a;i<b;++i)
#define fa(i,a) for(auto i:a)
#define ii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));
if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename R, typename D> inline void Min(R &a, D b){if(a>b) a=b;}
template <typename D, typename R> inline void Max(D &a, R b){if(a<b) a=b;}
const int N = 200005;
string t,s;
int k,cnt,cnt2;
int main(){
    ios_base::sync_with_stdio(NULL);
    cin. tie(NULL); cout. tie(NULL);
//    freopen(".inp" , "r", stdin);
//    freopen(".out", "w", stdout);
	cin>>t;s=t+t;cin>>k;
	fl(i,1,s.size()){
		if(s[i]==s[i-1]){
			++cnt;
			s[i]='?';
		}
	}
	fl(i,1,t.size()){
		if(t[i]==t[i-1]){
			++cnt2;
			t[i]='?';
		}
	}
	cout<<1ll*cnt*(k/2)+cnt2*(k&1);
    return 0;
}