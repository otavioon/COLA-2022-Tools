#include <iostream>
#include <algorithm>
using namespace std;
int a1[1000010];
int a2[1000010];
int a3[1000010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a2[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a3[i];
	}
	
	sort(a1+1,a1+n+1);
	sort(a2+1,a2+n+1);
	sort(a3+1,a3+n+1);
	int j=1;
	int k=1;
	long long int sum=0;
	for(int i=1;i<=n;i++){
		while(a1[j]<=a2[i]&&j<=n){
			j++;
		} 
		
		while(a3[k]<=a2[i]&&k<=n){
			k++;
		}
		
		sum=sum+(j-1)*(n-k+1);
	} 
	cout<<sum;
}