#include<stdio.h>
#include<string>
#include<string.h>
#include<utility>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<bitset>
#include<tuple>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    char s[105]={};
    int k;
    scanf("%s%d",s,&k);
    int length = strlen(s);
    int beg,end;
    char keep=s[0];
    for(beg=0;s[beg]==keep&&beg<length;beg++);
    keep = s[length-1];
    for(end=length-1;s[end]==keep&&end>=0;end--);
    ll num=0;
    int pat=1;
    //printf("%d %d\n",beg,end);
    keep = s[beg];
    for(int i=beg+1;i<=end;i++){
        if(s[i]==keep){
            pat+=1;
        }
        else{
            keep=s[i];
            num+=pat/2;
            pat=1;
        }
    }
    num+=pat/2;
    if(beg>end){
        printf("%d\n",(length*k/2));
        return 0;
    }
    ll num1 = beg/2 + (length-end-1)/2;
    ll num2 = 0;
    if(s[0]==s[length-1]){
        num2 = (beg + length - end-1)/2;
    }
    else{
        num2 = num1;
    }
    ll ans = num * k + num1 + num2*(k-1);
    //printf("%ld %lld %lld\n",num,num1,num2);
    printf("%lld\n",ans);
    return 0;
}