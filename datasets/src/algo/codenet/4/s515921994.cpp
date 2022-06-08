#include <iostream>
using namespace std;
int main(void){
    int N,K;
    cin>>N>>K;
    int D[K];
    for(int i=0;i<K;i++){
        cin>>D[i];
    }
    int check[10];
    for(int i=0;i<10;i++){
        check[i]=1;
    }
    for(int i=0;i<10;i++){
       for(int j=0;j<K;j++){
           if(i==D[j]) check[i]=0;
       }
    }
    for(int i=N;i<100000;i++){
        int num=i;
        int a=num%10; num=num/10;
        int b=num%10; num=num/10;
        int c=num%10; num=num/10;
        int d=num%10; num=num/10;
        int e=num%10;
        if(check[a]!=0&&check[b]!=0&&check[c]!=0&&check[d]!=0&&check[e]!=0) {cout<<i; break; }
        else if(check[a]!=0&&check[b]!=0&&check[c]!=0&&check[d]!=0&&e==0) {cout<<i; break;}
        else if(check[a]!=0&&check[b]!=0&&check[c]!=0&&d==0&&e==0) {cout<<i; break;}
        else if(check[a]!=0&&check[b]!=0&&c==0&&d==0&&e==0) {cout<<i; break;}
        else if(check[a]!=0&&check[b]==0&&c==0&&d==0&&e==0) {cout<<i; break;}
    }
    
    return 0;
}
