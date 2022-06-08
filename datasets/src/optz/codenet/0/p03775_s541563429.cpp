#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	
	int i;
	long int a[200000];
	int n;
	int ns;
	ns=0;
	int k;
	
	
	cin>>n;
	
	for(i=1;i<=100000;i++){
		if(n>=i*i){
			ns=i+1;
		}
	}
	
	for(i=1;i<=ns;i++){
		if(n%i==0){
			k=n/i;
		}
	}
	
	if(1<=k&&k<10){
		cout<<1<<"\n";
	}
	
	if(10<=k&&k<100){
		cout<<2<<"\n";
	}
	
	if(100<=k&&k<1000){
		cout<<3<<"\n";
	}	
	
	if(1000<=k&&k<10000){
		cout<<4<<"\n";
	}
	
	if(10000<=k&&k<100000){
		cout<<5<<"\n";
	}
	
	if(100000<=k&&k<10000000){
		cout<<6<<"\n";
	}		
	
	return 0;
}


