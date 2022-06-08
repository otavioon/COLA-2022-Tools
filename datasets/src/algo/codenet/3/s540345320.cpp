#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>

using namespace std;

int n,a[100010],b[100010],c[100010],hb[100010],hc[100010],mb=0,mc=0,md=0,r=0;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int i=0;i<n;i++)scanf("%d",&c[i]);
    sort(a,a+n);sort(b,b+n);sort(c,c+n);
    
    for(int i=0;i<n;i++){
        while(mb<n){
            if(a[mb]<b[i])mb++;
            else break;
        }
        hb[i]=mb;
    }
    
    for(int i=0;i<n;i++){
        while(mc<n){
            if(b[mc]<c[i]){
                md+=hb[mc];
                mc++;
            }
            else break;
        }
        r+=md;
    }
    //for(int i=0;i<n;i++)printf("%d  ",hc[i]);
    printf("%d\n",r);
    
}
