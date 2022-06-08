#include <bits/stdc++.h>
using namespace std;

int main (){
    long long k,ans=0,memo=0,ma=1,mb=1,ans1=0;
    char s[105];
    long long n,i;
    cin >> s >> k;
    n=strlen(s);
    if(s[0]!=s[n-1]){
    	memo=1;
    	for(i=1;i<n;i++){
    		if(s[i-1]==s[i]){
    			memo++;
    		} else {
    			ans+=((memo-memo%2)/2);
    			memo=1;
    		}
    	}
    	ans+=((memo-memo%2)/2);
    	ans=ans*k;
    } else {
    	memo=1;
    	for(i=1;i<n;i++){
    		if(s[i-1]==s[i]){
    			memo++;
    		} else {
    			ans+=((memo-memo%2)/2);
    			memo=1;
    		}
    	}
    	ans+=((memo-memo%2)/2);
    	ans=ans*k;
    	for(i=1;i<n;i++){
    		if(s[i]==s[0]) ma++;
    		else break;
    	}
    	for(i=n-2;i>=0;i--){
    		if(s[i]==s[n-1]) mb++;
    		else break;
    	}
    	if(ma==n){
    		ans=(n*k)/2;
    	} else if(ma==1&&mb==1) {
    		ans+=(k-1);
    	} else if(ma%2==1&&mb%2==1){
    		ans+=((k-1));
    	}
    }
    cout << ans << endl;
    return 0;
}