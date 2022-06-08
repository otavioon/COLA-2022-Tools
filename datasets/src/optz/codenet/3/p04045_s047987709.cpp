# include <iostream>
# include <queue>
using namespace std;
queue<int> q;
int f[10],s,k,vc,i;
int main () {
    cin>>s>>k;
    for(i=1;i<=k;i++){
        cin>>vc;
        f[vc]=1;
    }
    for(i=1;i<10;i++)
        if(f[i]==0)
            q.push(i);
    while(!q.empty()){
        vc=q.front();
        q.pop();
        if(vc>=s){
            cout<<vc<<"\n";
            return 0;
        }
        for(i=0;i<10;i++)
            if(f[i]==0)
                q.push(vc*10+i);
    }
    return 0;
}
