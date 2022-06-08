#include<cstdio>
#include<set>
#include<algorithm>
int N;
std::multiset<int>A;
int main(){
	scanf("%d",&N);
	for(int i=0,a;i<N;i++)scanf("%d",&a),A.insert(a);
	int ans=0;
	while(A.size()){
		int x=*A.rbegin(),y=1;
		A.erase(A.find(x));
		while(y<=x)y*=2;
		std::multiset<int>::iterator it=A.find(y-x);
		if(it!=A.end()){
			A.erase(it);
			ans++;
		}
	}
	printf("%d\n",ans);
}