#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,x,n;
    cin>>n>>k;
    set<int>s1;
    for(int i=1;i<=k;i++){
        cin>>x;
        s1.insert(x);
    }
    int s[10],r=0;
    while(n!=0){
        int t=n%10;
        s[r++]=t;
        n=n/10;
    }
    reverse(s,s+r);
    int y=0,i;
    //r=s.size();
    for(i=0;i<r;i++){
        //d=s[i]-'0';
        if(!s1.count(s[i]))
            y++;
        else
            break;
    }
    if(y==r){
        for(int i=0;i<r;i++)
            cout<<s[i];
    }
    else if(s[0]==9){
        for(int i=1;i<10;i++){
            if(!s1.count(i)){
                cout<<i;
                break;
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=0;j<10;j++){
                if(!s1.count(j)){
                    cout<<j;
                    break;
                }
            }
        }
    }
    else{
        //cout<<i;
        for(int j=i;j>=0;j--){
            //d=s[j]-'0';
            //cout<<d<<endl;
            for(int l=s[j]+1;l<10;l++){
                if(!s1.count(l)){
                    for(int i=0;i<j;i++)
                        cout<<s[i];

                    cout<<l;
                    for(int i=j+1;i<r;i++){
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
