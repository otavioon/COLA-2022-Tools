#include <bits/stdc++.h>
using namespace std;
int main(){
long long c,e,f,g=0; 
long long d=0;
long long counter=0;
long long counter1=1;
string S; cin>>S;
char a=S.at(0);
char b=a;
for(long long i=1;i<S.size();i++){
if((a==S.at(i))){
counter1++;}
else{
if(g==0){
c=counter1;
counter1=1;
g++;}
counter+=counter1/2;
a=S.at(i);
counter1=1;}}
cin>>e;
if(counter1==S.size()){
f=(counter1*e)/2;}
else{
if(a==b){
d=(c+counter1)/2;}
else{
counter+=counter1/2;}
f=counter*e+d*(e-1)+c/2+counter1/2;}
cout<<f<<endl;}
