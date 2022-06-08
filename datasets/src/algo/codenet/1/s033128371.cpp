#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int a[3],b[3],c[3],d[2];
	bool f=false;

	cin>>a[0]>>b[0]>>c[0];
	d[0]=b[0]-a[0]; //a2-a1;
	d[1]=c[0]-b[0];	//a3-a2;
	for(int i=1;i<3;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(d[0]!=b[i]-a[i]||d[1]!=c[i]-b[i])
			f=true;
	}
	if(f)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

}