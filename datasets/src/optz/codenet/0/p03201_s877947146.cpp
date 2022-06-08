#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+7;
int read(){
    int c = getchar(),Nig = 1,x = 0;
    while(!isdigit(c))
        c = getchar();
    if(c == '-')
        Nig = -1,c = getchar();
    while(isdigit(c))
        x = ((x<<1) + (x<<3)) + (c^'0'),c = getchar();
    return Nig*x;
}
#define read read()
int a[maxn],n,ans;
int main(){
    n = read;
    for(int i=0;i<n;i++)
        a[i] = read;
    for(int k=1<<30;k;k>>=1){
        int l = 0,r = n-1;
        while(l<r){
            if(a[l] == -1 || (~a[r] && a[l]+a[r]<k))
                l++;
            else if(a[r] == -1 || a[l]+a[r]>k)
                r--;
            else{
                ans++;
                a[l] = a[r] = -1;
                l++,r--;
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
