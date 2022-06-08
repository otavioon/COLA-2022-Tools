#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string a;
char lst;
long long k,ans,cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>k;
    int len=a.length();
    if(len==1){
	printf("%lld\n",k/2);
	return 0;
    }
    lst=a[0];cnt=1;
    for(int i=1;i<len;i++){
	if(a[i]==lst)cnt++;
	else ans+=k*(cnt/2),cnt=1,lst=a[i];
    }
    if(a[0]==a[len-1]){
	int cnts=0,cntt=0;
	for(int i=0;i<len;i++){
	    if(a[i]==a[0])cnts++;
	    else break;
	}
	for(int i=len-1;i>=0;i--){
	    if(a[i]==a[len-1])cntt++;
	    else break;
	}
	if(cnts==len){
	    printf("%lld\n",len*k/2);
	    return 0;
	}
	if((cnts+cntt)%2==0)ans+=(k-1)*(cnts+cntt)/2;
	else ans+=(k-1)*(cnts+cntt+1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}
