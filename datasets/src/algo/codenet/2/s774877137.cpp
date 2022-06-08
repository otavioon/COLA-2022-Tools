#include <iostream>
#include <set> 
using namespace std;
int main()
{
	multiset<int>s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long tmp;
		cin>>tmp;
		s.insert(tmp);
	}
	int cnt=0,j=0;
	while(!s.empty()){
		long long la=*--s.end(),fi=*s.begin(),y=1;
		s.erase(la);
		while(y<la+fi){
			y*=2;
			if(y==la+fi){
				cnt++;
				s.erase(fi);
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}