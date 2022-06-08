#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
int main(){
	int k,a;
	char p[10];
	set<int>q;
	scanf("%s",&p);
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&a);
		q.insert(a);
	}
	for(int i=0;i<strlen(p);i++){
		if(q.count(p[i]-'0')==1)printf("%d",p[i]-'0'+1);
		else printf("%c",p[i]);
	}
	printf("\n");
	return 0;
}