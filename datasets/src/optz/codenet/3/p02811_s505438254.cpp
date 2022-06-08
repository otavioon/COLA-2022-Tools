#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    string a1="";
    string b1="";
    for(int i=0;i<n;i++){
        a1+= to_string(a[i]);
    }
    for(int i=0;i<n;i++){
        b1+=to_string(b[i]);
    }
    string aa=a1;
    string bb=b1;
    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());
    int rank1=1,rank2=1;
    do{
        if(a1==aa) {break;}
       rank1++; 
    }while(next_permutation(aa.begin(),aa.end()));
    
       do{
        if(b1==bb){ break;}
       rank2++; 
    }while(next_permutation(bb.begin(),bb.end()));
    
  
    if(rank1>=rank2){
        cout<<rank1-rank2;
    }
    else{
        cout<<rank2-rank1;
    }
    return 0;
}

