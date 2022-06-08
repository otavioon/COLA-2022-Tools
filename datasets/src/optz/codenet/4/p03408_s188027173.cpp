#include <bits/stdc++.h>
#define N 105
using namespace std;

int n,m;
string s[N];
string ss[N];
set<string> sss;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        sss.insert(s[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>ss[i];
    set<string>::iterator it = sss.begin();
    int sum =  0;
    for(it;it!=sss.end();it++){
        int ans = 0;
        for(int i=0;i<n;i++)
            if(s[i]==*it)
                ans++;
        for(int i=0;i<m;i++)
            if(ss[i]==*it)
                ans--;
        if(ans)
            sum = max(sum,ans);
    }
    cout<<sum<<endl;
    return 0;
}