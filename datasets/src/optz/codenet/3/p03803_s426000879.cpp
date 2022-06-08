#include <iostream>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
if(1<=a<=13 &&1<=b<=13){
if(a==b){
    cout<<"Draw \n";
}
 if(a==1 ||a>b ){
   if(b!=1){
    cout<<"Alice \n";
}
   else{
    cout<<"Bob \n";
}
}
 if(b==1 || a<b ){
   if (a!=1){
    cout<<"Bob \n";
}
   else{
    cout<<"Alice \n";
}
}
}
}