#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100
int K,N;
char str[MAXN+5];

int main(){
    scanf("%s%d",str+1,&K);
    N=strlen(str+1);
    bool flag=0;
    for(int i=1;i<N;i++)
        if(str[i]!=str[i+1]){
            flag=1;
            break;
        }
    if(!flag){
        printf("%lld",(long long)K*N/2);
        return 0;
    }
    //BBBCBCCAACBACBABCCACCBBAACCABBACBCAABCCCBAABCCAACCBACCCBCBBABAAAABBCBABAAAAB
    //BBBAB
    int cnt=0,tmp=0;
    for(int i=2;i<=N;i++)
        if(str[i]==str[i-1])
            cnt++,i++;
    tmp=cnt;
    //if(str[1]!=str[2])
        cnt+=str[N]==str[1];
    long long Ans1=(long long)cnt*(K-1)+tmp;
    cnt=0,tmp=0;
    for(int i=N;i>1;i--)
        if(str[i]==str[i-1])
            cnt++,i--;
    tmp=cnt;
    if(str[N]!=str[N-1])
        cnt+=str[N]==str[1];
    long long Ans2=(long long)cnt*(K-1)+tmp;
    printf("%lld",min(Ans1,Ans2));
}
