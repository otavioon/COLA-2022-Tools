#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string str;
char lst;
long long k,ans,cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>str>>k;
    int len=str.length();
    if(len==1){
	printf("%lld\n",k/2);
	return 0;
    }
    lst=str[0];cnt=1;
    for(int i=1;i<len;i++){
	if(str[i]==lst)cnt++;
	else ans+=k*(cnt/2),cnt=1,lst=str[i];
    }
    ans+=k*(cnt/2);
    if(str[len-1]==str[0]){
	int cnts=0,cntt=0;
	for(int i=0;i<len;i++){
	    if(str[i]==str[0])cnts++;
	    else break;
	}
	for(int i=len-1;i>=0;i--){
	    if(str[i]==str[len-1])cntt++;
	    else break;
	}
	if(cnts==len){
	    printf("%lld\n",len*k/2);
	    return 0;
	}
	if(cnts%2&&cntt%2)ans+=(k-1);
    }
    if(str[len-1]==str[0]&&str[len-2]!=str[len-1])ans+=(k-1);
    printf("%lld\n",ans);
    return 0;
}
