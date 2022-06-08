#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[3][100005];
int main(){
    int n;
    scanf("%d",&n);
    ll i1=n-1,i2=0,i3=0,sum=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        sort(a[i],a[i]+n);
    }
    while(i2<n){
        while(a[1][i2]>a[0][i1]&&i1<n) i1++;
        while(a[1][i2]>a[2][i3]&&i3<n) i3++;
        //printf("%lld %lld %lld\n",i1,i2,i3);
        sum+=(n-i3)*i1;
        i2++;
    }
    printf("%lld",sum);


}
