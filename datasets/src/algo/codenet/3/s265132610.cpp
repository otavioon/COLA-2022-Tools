#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
long long n;
long long a[1000003],b[1000003],c[1000003];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
    	cin>>b[i];
	}
	for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
    sort(a+1,a+1+n),sort(b+1,b+1+n),sort(c+1,c+1+n);
    long long sum=0;
    long long ai=0,ci=0;
    for(int i=1;i<=n;i++){
        while(a[ai+1]<b[i]&&ai+1<=n){
        	ai++;
		}
        while(c[ci+1]<=b[i]&&ci+1<=n){
        	ci++;
		}
        sum+=ai*(n-ci);
    }
    cout<<sum<<endl;
    return 0;
}
/*

in:
2
1 5
2 4
3 6

out:
3

*/