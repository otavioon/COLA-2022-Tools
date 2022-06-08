#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n,a[100000],b[100000],c[100000];
    ll ans=0,l,r,mid,add;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    for(int i=0;i<n;i++){
        l=0;
        r=n-1;
        while(l<=r){
            mid=(l+r)/2;
            if(a[mid]<b[i]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        add=l;
        l=0;
        r=n-1;
        while(l<=r){
            mid=(l+r)/2;
            if(c[mid]<=b[i]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }//printf("%lld\n",add);
        add*=(ll)(n-l);
        ans+=add;//printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}