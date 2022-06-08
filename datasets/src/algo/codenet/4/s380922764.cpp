#include<iostream>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<algorithm>
#include<functional>
void hoge();
using namespace std;

int n,k,d[9],dd[4],ans=0,a,i,j;
bool f[4]={};
int main() {
    cin>>n>>k;
    for(i=0;i<k;i++)cin>>d[i];
    
    ans=n;
aaa:
    hoge();
    for(i=0;i<4;i++){
        for(j=0;j<k;j++){
            if(dd[i]==d[j]&&f[i]==0){
                ans++;
                goto aaa;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
void hoge(){
    int ans2,ans3;
    ans2=ans;
    ans3=ans;
    for(i=3;i>=0;i--){
        ans2=ans3%10;
        ans3/=10;
        dd[i]=ans2;
    }
    if(dd[0]==0){
        f[0]=1;
    }else{
        f[0]=0;
    }
    if(dd[1]==0&&dd[0]==0){
        f[1]=1;
    }else{
        f[1]=0;
    }
    if(dd[2]==0&&dd[1]==0&&dd[0]==0){
        f[2]=1;
    }else{
        f[2]=0;
    }
}
