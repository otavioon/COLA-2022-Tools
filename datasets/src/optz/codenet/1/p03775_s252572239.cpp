#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    long long n;
    long long ans=1;
    long long k;
    
    cin >> n;
    
    for(long long i=1; i<=100000; i++){
        
        if(i*i>n){
            
            break;
            
        }
        
        if(n%i==0){
            
            k = n / i;
            
        }
        
    }
    
    for(int j=1; j<=10; j++){
        
        if(k>=pow(10, j)){
            
            ans = j + 1;
            
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
    
}