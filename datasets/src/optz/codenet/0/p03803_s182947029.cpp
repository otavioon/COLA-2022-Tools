#include<iostream>
#include<string>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a==b){
        cout << "Draw" << endl;
    }else if ((a==1&&b!=1)||a>b){
        cout << "Alice" << endl;
    }else if ((b==1&&a!=1)||a<b){
        cout << "Bob" << endl;
    }
        
    return 0;
}