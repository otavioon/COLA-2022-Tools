#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b;
    cin>>a>>b;
    if (a=b||(a==b)){
        cout<<"Draw"<<endl;
    }
    else if (b>a||b==1){
        cout<<"Bob"<<endl;
    }
    else {
        cout<<"Alice"<<endl;
    }
}