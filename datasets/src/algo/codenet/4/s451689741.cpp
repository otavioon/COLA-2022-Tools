#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e18
typedef long long ll;
typedef pair<int,int> P;

set<int>ban,ban1,num;
int n,k;

void dfs(int nn,int digit){
    if(digit == 5){
        if(nn>n){
            num.insert(nn);
        }
        return;
    }
    for(auto itr = ban.begin();itr!=ban.end();++itr){
        int x = *itr;
        int add = (int)pow(10,digit);
        int y = nn+x*add;
        if(y>=n){
            num.insert(y);
        }
        else dfs(y,digit+1);
    }
}

int main(void){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int d;
        cin>>d;
        ban1.insert(d);
    }
    for(int i=0;i<10;i++){
        if(ban1.count(i)==0)ban.insert(i);
    }
    dfs(0,0);
    for(auto itr = num.begin();itr!=num.end();++itr){
        cout<<(*itr)<<endl;
        return 0;
    }
	return 0; 
}