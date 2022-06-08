#include<bits/stdc++.h>
using namespace std;

int h[100001];

int main(){
    long long int n, a, b;
    scanf("%lld %lld %lld",&n,&a,&b);
    long long int sum=0;
    for(int i=0;i<n;++i){
        scanf("%d",&h[i]);
        sum += h[i];
    }
    long long int d = a + b * (n - 1);
    long long int cnt = ceil((a < b * n - 1) ? (double)sum / d : (double)sum / a);
    printf("%lld\n",cnt);

    return 0;
}
