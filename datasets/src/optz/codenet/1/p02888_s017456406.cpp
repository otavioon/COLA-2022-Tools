#include<stdio.h>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include<complex>
#include<math.h>
#include<string>
#include<sstream>

using namespace std;


int main(){
    int N;
    cin>>N;
    int l[N];
    for (int i = 0; i < N; i++){
        cin >> l[i];
    }
    int ans=0;
    for (int i = 2; i < N; i++){
        for (int j = 1; j < i; j++){
            for (int k = 0; k < j; k++){
                if((l[i]+l[j])<l[k]){
                }
                else if((l[j]+l[k])<l[i]){
                }
                else if((l[k]+l[i])<l[j]){
                }
                else{
                    ans++;
                }
            }
            
        }
        
    }
    cout << ans << endl;
    return 0;
}