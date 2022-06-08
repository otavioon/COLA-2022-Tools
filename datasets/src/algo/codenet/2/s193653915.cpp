#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
multiset<int>se;
int main(){
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&x),se.insert(x);
    int ans=0;
    while(se.size()>1){
        int x=*se.rbegin();
        int now=1;
        while(now<=x) now<<=1;
        auto it=se.find(now-x);
        if(it==se.end()) se.erase(se.find(x));
        else ans++,se.erase(it),se.erase(se.find(x));
    }
    printf("%d",ans);
}
