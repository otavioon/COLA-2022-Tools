#include<bits/stdc++.h>

using namespace std;

char d[100004];
long long k, cnt=0;
vector<long long> v;

int main() {
    scanf("%s",d);
    scanf("%lld",&k);
    char bef=d[0]; int cc=1;
    for (long long i=1; i<strlen(d); i++) {
        if (bef==d[i]) cc++;
        else {
            v.push_back(cc); cc=1;
            bef=d[i];
        }
    }
    if (cc!=1) v.push_back(cc);
    /* for (int i=0; i<v.size(); i++) printf("%d ",v[i]);
    printf("\n"); */
    if (v.size()==1) {
        printf("%lld",(v[0]*k)/2);
    }
    else if (v.size()==0) printf("0");
    else if (d[strlen(d)-1]==d[0] && k>1) {
        for (long long i=1; i<v.size()-1; i++) cnt+=v[i]/2;
        cnt=cnt*k;
        cnt+=(v[0]+v[v.size()-1])/2*(k-1);
        cnt+=v[0]/2+v[v.size()-1]/2;
        printf("%lld",cnt);
    }
    else {
        for (int i=0; i<v.size(); i++) cnt+=v[i]/2;
        printf("%lld",cnt*k);
    }
    return 0;
}