#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200000+100],ans;
set <long long> st;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		st.insert(a[i]);
	}
	for(int i=0;i<n;i++){
		t=1;
		for(int j=1;j<30;j++){
			t*=2;
			if(a[i]>t && st.find(a[i]-t)!=st.end()){
				ans++;
				st.erase(st.find(a[i]-t));
				st.erase(st.find(a[i]));
				break;
			}
		}
	}
	cout<<ans;
}

