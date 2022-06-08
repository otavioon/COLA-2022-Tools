#include <iostream>
#include <string>
using namespace std;

int main(){

    int N;
    cin>>N;

    int A[N];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }

    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j){
                if(((A[i]+A[j])&(A[i]+A[j]-1))==0){
                    count = count+1;
                }    
            }
               
        }
    }
    
    cout<<count<<endl;
    return 0;
}