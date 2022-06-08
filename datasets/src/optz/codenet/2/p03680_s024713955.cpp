#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
int n;
scanf("%d",&n);
vector<int> v;
for(int i=0;i<n;i++)
{
int z;
scanf("%d",&z);
z--;
v.push_back(z);
}
int now=0,c=0;
while(true)
{
if(now==1)
{
printf("%d\n",c);
break;
}
if(c>=n)
{
printf("−1\n");
break;
}
c++;
now=v[now];
}
}