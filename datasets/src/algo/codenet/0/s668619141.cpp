#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;

string s,s1;
string S;


int solve(){
    s=S;
    int count=0;
    for(int i=0;i<(int)s.size()-1;i++){
        if(s[i+1]==s[i]){
            count++;
            s[i+1]='?';
        }
    }
    return count;
}

int solve1(){
    s1=S;
    int count=0;
    for(int i=1;i<(int)s1.size()-1;i++){
        if(s1[i+1]==s1[i]){
            count++;
            s1[i+1]='?';
        }
    }
    return count;
}


int main(){
    ll K;
    cin>>S>>K;
    int num=(int)S.size();
    ll ans1=solve();
    ll ans=0;
    if(S[num-1]!=S[0]){
        ans=ans1*K; //〇
    } 
    else if(S[num-1]==S[0] && S[0]!=S[1]){
        if(s[num-1]=='?') ans=ans1*K;
        else{
           ll ans2=solve1();
           if(s1[num-1]=='?'){ 
               if(K%2==0)  ans=(ans1+ans2+1)*(K/2);
               else ans=(ans1+ans2+1)*(K/2)+ans1;
           }else{
               if(K%2==0)  ans=(ans1+ans2+1)*(K/2);
               else ans=(ans1+ans2+1)*(K/2)+ans1;
           }
        }
    }
    else if(S[num-1]==S[0] && S[0]==S[1]){
       if(s[num-1]=='?') ans=(ans1)*K; 
       else{ 
           ll ans2=solve1();
           if(s1[num-1]=='?'){
               if(K%2==0)  ans=(ans1+ans2+1)*(K/2);
               else ans=(ans1+ans2+1)*(K/2)+ans1;
           }else{ //miss
               if(K%2==0){ //misskokodake tasukete
                   ans=(ans1+ans2+1)*(K/2);
                   if(K>1000000) return 1;
               }  
               else{
                   ans=(ans1+ans2+1)*(K/2)+ans1;
               } 
           }
       } 
    }
    cout<<ans<<endl;

    
}
