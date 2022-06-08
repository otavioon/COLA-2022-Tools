#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,x;
    string s;
    cin>>s>>k;
    set<int>s1;
    for(int i=1;i<=k;i++){
        cin>>x;
        s1.insert(x);
    }

    int y=0,d,i;
    for(i=0;i<s.size();i++){
        d=s[i]-'0';
        if(!s1.count(d))
            y++;
        else
            break;
    }
    if(y==s.size())
        cout<<s<<endl;
    else{
        //cout<<i;
        for(int j=i;j>=0;j--){
            d=s[j]-'0';
            //cout<<d<<endl;
            for(int l=d+1;l<10;l++){
                if(!s1.count(l)){
                    for(int i=0;i<j;i++)
                        cout<<s[i]-'0';

                    cout<<l;
                    for(int i=j+1;i<s.size();i++){
                        //int d=s[i]-'0';
                        for(int p=0;p<10;p++){
                            if(!s1.count(p)){
                                cout<<p;
                                break;
                            }
                        }
                    }
                    return 0;
                }
            }
        }
    }

}
