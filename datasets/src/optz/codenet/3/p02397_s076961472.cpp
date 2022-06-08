#include <stdio.h>
#include <cstdio>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> que1,que2;
	int x1,y2,tmp,count;
	tmp=count=0;
	do{
	scanf("%d",&x1);scanf("%d",&y2);
	if(x1==0)
	if(y2==0)break;

	if(x1<y2){
		tmp=x1;x1=y2;y2=tmp;
	}
	
	que1.push(x1);
	que2.push(y2);

	count++;
	}while(1);

	for(int i=0;i<count;i++)
	{
		printf("%d %d\n",que1.front(),que2.front());
		que1.pop();que2.pop();

	}
}