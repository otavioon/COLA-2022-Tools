#include <iostream>
#include<algorithm>

using namespace std;

long long abss(int* A,int n,int b){
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(A[i]-b);
    }
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
        A[i]=A[i]-(i+1);
    }

    
   /* for(int i=1;i<n;i++){
        long long v=A[i];
        int j=i-1;
        while(j>=0&&A[j]<v){
            swap(A[j],A[j+1]);
            j--;
        }
        A[j+1]=v;
    }*/
    sort(&A[0],&A[n]);
    
    long long a;
    if(n%2==1){
        a=A[n/2];
        cout<<abss(A,n,a)<<endl;
        return 0;
    }else{
        long long a=abss(A,n,A[n/2]);
        long long b=abss(A,n,A[(n/2)-1]);
        cout<<min(a,b)<<endl;
    }
    
    //cout<<a<<endl;
 //   int ans=abss(A,n,a);
   // cout<<ans<<endl;

return 0;
}