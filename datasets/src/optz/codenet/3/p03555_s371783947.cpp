#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
bool bj[1000001];
int main()
{
int k;
scanf("%d",&k);
deque<P> q;
q.push_back(make_pair(1,1));
while(!q.empty())
{
  P a=q.front();
  q.pop_front();
  if(bj[a.first])
    continue;
  bj[a.first]=1;
  if(!a.first)
  {
  	printf("%d\n",a.second);
  	return 0;
  }
  q.push_front(make_pair((a.first*10)%k,a.second));
  q.push_back(make_pair((a.first+1)%k,a.second+1));
}
return 0;
} 