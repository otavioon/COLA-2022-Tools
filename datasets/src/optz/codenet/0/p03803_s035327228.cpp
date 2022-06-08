#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main (){
    int a,b; cin>>a>>b;
    if(a==1||b==1){
        if(a==1&&b!=1){
            cout<<"Alice";
        } if(b==1&&a!=1){
        cout<<"Bob";}
        if(a==b){
            cout<<"Draw";
        }
    } else{
        if(a>b){
            cout<<"Alice";
        } if(b>a){
        cout<<"Bob";}
        if(a==b){
            cout<<"Draw";}}}























