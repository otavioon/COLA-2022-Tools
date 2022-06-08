#include<iostream>
using namespace std;
int main(){
    int n,x,i,max,min;
    int a[1001];
    int sum=0;
    cin>>n;
    for(i=0;i<=n;i++){
        cin>>x;
        a[i]=x;
        sum=a[i]+sum;
        if(i==1){
            max=a[i];
            min=a[i];
        }
        else{
        
        if(a[i]>a[i-1]){
            max=a[i];
        }
        else if(a[i]<a[i-1]){
            min=a[i];
        }
        }
    }
    cout<<min<<" "<<max<<" "<<sum<<endl;
    return 0;
}
