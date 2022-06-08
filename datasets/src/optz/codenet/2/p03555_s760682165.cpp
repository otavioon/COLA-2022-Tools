#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,p;
    cin>>s>>p;
   int k=0;
   stack<char>j;
   for(int i=0;i<s.size();i++)
   {
       j.push(s[i]);
   }
   for(int i=0;i<s.size();i++)
   {
       if(j.top()==p[i])
       {
           j.pop();
           k++;
       }
   }
   if(k==p.size())
   {
       cout<<"YES"<<endl;
   }
   else
   {
        cout<<"NO"<<endl;
   }
}
