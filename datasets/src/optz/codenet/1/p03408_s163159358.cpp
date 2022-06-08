#include<iostream>
#include<utility>
#include<string>
#include<algorithm>
using namespace std;
pair<string,int>p[101];

int main()
{
    int n,m,i,j,k;
    string s;
    cin>>n;
    bool flag=true;
    for(i=0;i<101;i++)p[i].second=0;
    k=0;
    for(i=0;i<n;i++){
        cin>>s;
        flag=true;
        for(j=0;j<101;j++){
            if(s==p[j].first){
                p[j].second++;
                flag=false;
                break;
            }
        }
        if(flag==true) {
            p[k].first=s;
            p[k].second=1;
            k++;
        }
    }
//    for(i=0;i<k;i++){
//        cout<<p[i].second<<endl;
//    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>s;
        for(j=0;j<101;j++){
            if(s==p[j].first){
                p[j].second--;
                break;
            }
        }
    }
    int maxi=0;
    for(i=0;i<101;i++){
        maxi=max(maxi,p[i].second);
    }
    cout<<maxi<<endl;
}
