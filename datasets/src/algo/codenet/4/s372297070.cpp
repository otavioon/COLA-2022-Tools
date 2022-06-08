#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    char x;
    int k;
    cin>>n>>k;
    set<char> s;
    for(int i=0;i<k;i++)cin>>x,s.insert(x);
    bool carry;
    for(int i=n.size()-1;i>=0;i--){
        carry =false;
        while(s.count(n[i])){
            if(n[i]=='9') n[i]='0',carry=true;
            n[i]++;
        } 
    }
   char ch='1';
   while(s.count(ch))
       ch++;
   if(carry) n=ch+n;
    cout<<n;
}
