#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define tezz std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
signed main() {
    tezz
   string s;
   cin>>s;
   int n;
   cin>>n;
   string t=s;
   int i=0;int c=0;
  while(i<t.length()-1){
       for(int j=i+1;j<t.length();j++){
           if(i!=j && t[i]==t[j]){
               c++;
               i++;
               break;
               
           }
           
       }
       i++;
   }
   
   cout<<c*n<<endl;
 

}