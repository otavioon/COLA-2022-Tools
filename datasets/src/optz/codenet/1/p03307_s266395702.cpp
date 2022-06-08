#include <iostream>

using namespace std;

int main() {
    long long n;
    cin>>n;
    int i=1;
    while(true){
        long long nn = n*i++;
        if(nn%2==0){
            cout<<nn;
            return 0;
        }
    }
    
}
