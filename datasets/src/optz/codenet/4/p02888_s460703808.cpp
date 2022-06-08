#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
vector<int> v(3);

/*
struct tt{
int a,b,c;

bool operator< (const tt x){
    if(a<x.a)return 1;
    if(b<x.b)return 1;
    return c<x.c;
}
};
*/
//tt pp;

pair<int,pair<int,int> > pp;
set<pair<int,pair<int,int> > > st;

void back(int p,vector<int> &v,int con){
int a=v[0],b=v[1],c=v[2];
//cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;

if(con==3){
  if(a<b+c&&b<c+a&&c<a+b){
    if(a<b&&a<c)pp.first=a;
    else if(a<b||a<c)pp.second.first=a;
    else pp.second.second=a;
        if(b<c&&b<a)pp.first=b;
        else if(b<c||b<a)pp.second.first=b;
        else pp.second.second=a;
            if(c<a&&c<b)pp.first=c;
            else if(c<a||c<b)pp.second.first=c;
            else pp.second.second=c;
st.insert(pp);
}
return;
}

for(int i=p+1;i<n;i++){
if(con==0)v[0]=arr[i];
  else  if(con==1)v[1]=arr[i];
     else   if(con==2)v[2]=arr[i];
back(i,v,con+1);
}
return;
}

int main(){

cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
v[0]=arr[0];v[1]=arr[1];v[2]=arr[2];
back(-1,v,0);
cout<<st.size()<<'\n';
}
