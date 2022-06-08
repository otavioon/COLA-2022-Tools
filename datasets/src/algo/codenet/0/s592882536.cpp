#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    ll k;
    cin>>k;
    int l=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==s[0])
            {l++;}
        else
                break;
    }
    l++;
    ll c=0;
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            s[i+1]=125+i+1;
            c++;
        }
    }
    c=c*k;
    if(s[0]==s[s.length()-1])
    {
        if(l%2==1)
            c+=k-1;
    }
    cout<<c;


}

