#include<iostream>
using namespace std;

int main(void)
{
    int n,a[100000],b[100000],c[100000],work,i=0,j=0,k=0,k2=0,cnt=0,cnt_k=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                work=a[i];
                a[i]=a[j];
                a[j]=work;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]<b[j]){
                work=b[i];
                b[i]=b[j];
                b[j]=work;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(c[i]<c[j]){
                work=c[i];
                c[i]=c[j];
                c[j]=work;
            }
        }
    }
    
    for(j=0;j<n;j++){
        while(a[i]>=b[j]){
            i++;
            if(i>=n&&k>=n-1)break;
            if(i>=n){
                i=n-1;
                k++;
            }
        }
        while(b[j]>=c[k]){
            k++;
            if(k>=n&&i>=n-1)break;
            if(k>=n){
                k=n-1;
                i++;
            }
        }
        k2=k;
        while(b[j]<c[k2]){
            cnt_k++;
            k2++;
        }
        cnt+=(cnt_k)*(n-i);
        
        //cout<<"_"<<n-i<<"_"<<j<<"_"<<cnt_k<<"  "<<cnt<<endl;
        cnt_k=0;
    }
    cout<<cnt<<endl;
    return 0;
}
