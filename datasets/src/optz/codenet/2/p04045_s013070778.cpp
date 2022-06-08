#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,k,i,j;
vector<int> d;

void dfs(int);

int main(){
    cin>>n>>k;
    d.resize(k);
    for(i=0;i<k;i++){cin>>d[i];}

    dfs(n);
    return 0;
}

void dfs(int x){
    int dis,div=1,keta=0,num=x;

    while(num>0){//xの桁を得る
        num/=10;
        keta++;
    }

    bool distin=true;//嫌いな数字がなければtrue あればfalse
    for(i=0;i<keta;i++){//全桁について調べている
        dis=x/div;dis%=10;
        for(j=0;j<k;j++){
            if(dis==d[j]){//一つでもirohaちゃんが嫌いなものがあったらfalse
                distin=false;
                break;break;
            }
        }
        div*=10;
    }

    
    if(distin && x>=n){//irohaちゃんが嫌いな数字ではないとき
        cout<<x<<endl;
        return;
    }else{//嫌いな数があったら次へ(制約から一つずつ増やしていっても間に合う)
        dfs(x+1);
    }
}