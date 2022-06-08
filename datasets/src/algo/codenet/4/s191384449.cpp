#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){
    int a,b;
    int e;
    cin>>a>>b;
    vector<int>v(10,0);
    while(b--){
        int c;
        cin>>c;
        v[c]=c;
    }
    set<int>v1;
    for (int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        v1.insert(i);
    }
    for (int i=a;;i++)
    {
        e=i;
        int count1=0;
        while(v1.find(e%10)!=v1.end() and 1+floor(log10(e))>=1){
            ++count1;
            e/=10;
        }
        if(count1>=1+floor(log10(a)))
        {
            cout<<i;
            break;
        }
        
        
    }

    
}
