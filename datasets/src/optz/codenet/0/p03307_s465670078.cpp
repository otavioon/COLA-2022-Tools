#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n,j;
    int a[300000];
    cin >> n;
    int t=0;
    for(j=1;j<n+1;++j){
        cin >> a[j];
        t+=a[j]-j;
    }
     int num[1000000000] = {0}; 
    for (int i = 1; i < n; ++i) {
        num[a[i]-i+200000]++;  
    }
    int l=0,h=0;
    for (int i = -200000; i < 1000000000; ++i) {
        if(num[i]>l){
            l=num[i];
            h=num[i];
        }   
    }

    int t1,t2,t3,t4,t5,t6,s,m;
    s=t/n;
    t1=0;t2=0;t3=0;t4=0;t5=0;
    for(j=1;j<n+1;j++){
        t1+=abs(a[j]-j-1-s);
        t2+=abs(a[j]-j-s);
        t3+=abs(a[j]-j-s+1);
        t4+=abs(a[j]-j-s+2);
        t5+=abs(a[j]-j-s-2);
        t6+=abs(a[j]-j-h+200000);
    }
    m=t1;
    if(t2<m) m=t2;
    if(t3<m) m=t3;
    if(t4<m) m=t4;
    if(t5<m) m=t5;
    if(t6<m) m=t6;
    cout << int(m) <<endl;
}
