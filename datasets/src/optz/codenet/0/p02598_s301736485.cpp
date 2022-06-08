#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//typedef pair<int,int> pii;
#define int long long

int a[2000010];

int n,k;
int cal(int x){
    int ans=0;
    for(int i=1;i<=n;++i){
        if(a[i]/x>k){
            return 1e9;
        }
        ans=ans+(a[i]/x);
        if(ans>k){
            return 1e9;
        }
    }
    if(ans<0){
        return 1e9;
    }
    return ans;
}

signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    int l=0,r=1e9,mid;
    while(l<=r){
        mid=(l+r)/2;
        int f=cal(mid);
        if(f>k)l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",l);


}
