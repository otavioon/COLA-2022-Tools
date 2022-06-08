#include<bits/stdc++.h>
using namespace std;
int test;

int main(){
int n;
cin>>n;
int v[n];
bool us[n];
for(int i=0;i<n;i++){
	cin>>v[i];
	us[i]=false;
}

int pos=0,ans=0;
while(us[pos]==false&&pos!=1){
	us[pos]=true;
	pos=v[pos]-1;
	ans++;
	//cout<<pos<<endl;
}
if(pos==1)
cout<<ans<<endl;
else
cout<<-1<<endl;

return 0;
}
