#include <bits//stdc++.h>
using namespace std;
int main(void){
    int n,z=0,ans=0;
    cin >> n;
    int data[n];
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    
    for(int i=0;i<n;i++){
         ans++;
        z=data[z];
        if(z==2){
            cout << ans<< endl;
            return 0;
        }
         z--;
    }
            cout << "-1" << endl;
            return 0;
    
}
