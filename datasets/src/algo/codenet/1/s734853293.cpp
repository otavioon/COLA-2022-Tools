#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int s[3],t[3];
    for(int i=0;i<3;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s[i]=a-b;
        t[i]=b-c;
    }
    if(s[0]==s[1] && s[1]==s[2] &&t[0]==t[1] && t[1]==t[2])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
