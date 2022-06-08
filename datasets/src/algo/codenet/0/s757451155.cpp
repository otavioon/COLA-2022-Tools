#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	int kk;
	cin>>a;
	cin>>kk;
	if(a.size()==1){
		cout<<kk/2<<endl;
		return 0;
	}
	long long int cnt=0;
	int f=0,i,j,d=0,dd=0;
	if(a[0]==a[a.size()-1]){
		char s=a[0];
		for(i=0;a[i]==s&&i<a.size();i++) d++;
		for(j=a.size()-1;a[j]==s&&j>=0;j--) d++;
		if(d/2==a.size()){
			dd=1;
		}
		if(d%2==0&&dd==0){
			d=d/2;
			f=1;
		}
	}
	if(dd==1){
		cnt=(d/2)*kk;
		cout<<cnt/2<<endl;
		return 0;
	}
	if(f==1){
		for(int k=i;k+1<j;){
			if(a[k]==a[k+1]){
				cnt++;
				k+=2;
			}
			else{
				k++;
			}
		}
		cnt=kk*cnt+d*(kk-1);
		int r=0;
		char ss=a[a.size()-1];
		for(int t=a.size()-1;a[t]==ss;t--) r++;
		cout<<cnt+(r/2)<<endl;	
	}
	else{
		for(int i=0;i+1<a.size();){
			if(a[i]==a[i+1]){
				cnt++;
				i+=2;
			}
			else{
				i++;
			}
		}
		cnt=kk*cnt;
		cout<<cnt<<endl;		
	}
	return 0;
}