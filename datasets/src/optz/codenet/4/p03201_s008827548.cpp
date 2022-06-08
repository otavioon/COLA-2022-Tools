#include<bits/stdc++.h>
using namespace std;
long long a[100];
long long num[300005];
set<long long> s;
set<int >ss;
int cmp(int a,int b){
	return a>b;
}
int main(){
//	long long a[100];
	set<int>::const_iterator iter;
     set<int>::iterator first;
     set<int>::iterator second;
	a[0]=1;
	for(int i=1;i<=35;i++)
		a[i]=a[i-1]*2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		s.insert(num[i]);
	}
	sort(num,num+n,cmp);
	int cnt=0;
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=32;j++)
			if(s.count(num[i])&&a[j]>num[i]&&(a[j]-num[i])!=num[i]&&s.count(a[j]-num[i])&&a[j-1]<num[i]){
				if(ss.count(num[i])||ss.count(a[j]-num[i]))
					sum++;
				ss.insert(num[i]);
				ss.insert(a[j]-num[i]);
				cnt++;
			//	printf("%d %d %d\n",a[j],num[i],a[j]-num[i]);
			//	break;
			}
	}
	cout<<cnt-sum/2	<<endl;
} 