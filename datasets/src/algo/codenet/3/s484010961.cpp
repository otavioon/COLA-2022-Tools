#include<algorithm>
#include<bitset>
#include<iostream>
#include<iomanip>
#include<set>
#include<string>
#include<math.h>

using namespace std;

class zahyo{
	public:
	int x;
	int y;
	zahyo(){
		x=0;
		y=0;
	}
	zahyo(int x_,int y_){
		x=x_;
		y=y_;
	}
	void print(){
		cout<<x<<" "<<y;
	}
	zahyo operator+(zahyo add){
		add.x=this->x+add.x;
		add.y=this->y+add.y;
		return add;
	}
	zahyo operator-(zahyo add){
		add.x=this->x-add.x;
		add.y=this->y-add.y;
		return add;
	}
	bool operator==(const zahyo add) const{
		if(add.x==this->x and add.y==this->y){return true;}
		else{return false;}
	}
	bool operator!=(const zahyo add) const{
		if(add.x==this->x or add.y==this->y){return false;}
		else{return true;}
	}
	bool operator<(const zahyo add) const{
		if(this->x<add.x){return true;}
		else if(this->x==add.x and this->y<add.y){return true;}
		else{return false;}
	}
	bool operator>(const zahyo add) const{
		if(this->x>add.x){return true;}
		else if(this->x==add.x and this->y>add.y){return true;}
		else{return false;}
	}
	void input(){
		cin>>x>>y;
	}
};

long long int a[100000],b[100000],c[100000];
int main(){
	int n;
	long long int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	for(int i=0;i<n;i++){
		if(a[0]>b[i] or b[i]>c[n-1]){continue;}
		else{
			int aS=0;int aMorL=n;
			while(aMorL-aS>1){
				int temp=(aS+aMorL)/2;
				if(a[temp]<b[i]){
					aS=temp;
				}
				else{
					aMorL=temp;
				}
			}
			int bSorM=-1;int bL=n;
			while(bL-bSorM>1){
				int temp=(bSorM+bL)/2;
				if(c[temp]<=b[i]){
					bSorM=temp;
				}
				else{
					bL=temp;
				}
			}
			long long temp=(aS+1LL)*(n-bL);
			ans+=temp;
			//cout<<aS<<" "<<b[i]<<" "<<bL<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
