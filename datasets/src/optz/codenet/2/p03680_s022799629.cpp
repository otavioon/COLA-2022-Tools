#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,i,array1[N],counter=0;
map<int,int>visited;
scanf("%d",&n);
for(i=1;i<=n;++i){
    scanf("%d",&array1[i]);
}
i=1;
while(true){
    if(i==2){
        break;
    }
    counter++;
    if(visited[i]){
        counter=-1;
        break;
    }
    visited[i]=1;
    i=array1[i];
}
printf("%d",counter);

    return 0;
}
