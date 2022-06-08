#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int N,Q;
const int null =-1;
vector<ll> point(200000+1,0);
vector<P> hen(200000);
vector<P> hand(200000);
vector<int> par(200000+1);
vector<bool> flag(200000,true);
queue<int> fp;
void dis(){
    par.at(1)=1;
    for(int i=0;i<N-1;i++){
        if(hen.at(i).first==1&&flag.at(i)){
            par.at(hen.at(i).second)=1;
            fp.push(hen.at(i).second);
            flag.at(i)=false;
        }
    }
    while(!fp.empty()){
        int p=fp.front();
        fp.pop();
        for(int i=0;i<N-1;i++){
            if(hen.at(i).first==p&&flag.at(i)){
                par.at(hen.at(i).second)=p;
                fp.push(hen.at(i).second);
                flag.at(i)=false;
            }
            if(hen.at(i).second==p&&flag.at(i)){
                par.at(hen.at(i).first)=p;
                fp.push(hen.at(i).first);
                flag.at(i)=false;
            }
        }
    }
}
void getpoint(int a,int b){
    point.at(a)+=b;
    queue<int> son;
    for(int i=1;i<=N;i++){
        if(par.at(i)==a){
            point.at(i)+=b;
            son.push(i);
        }
    }
    while(!son.empty()){
        int f=son.front();
        son.pop();
        for(int j=1;j<=N;j++){
            if(par.at(j)==f){
                point.at(j)+=b;
                son.push(j);
            }
        }
    }
}
int main(){
    cin>>N>>Q;
    for(int i=0;i<N-1;i++)cin>>hen.at(i).first>>hen.at(i).second;
    for(int i=0;i<Q;i++)cin>>hand.at(i).first>>hand.at(i).second;
    
    dis();
    for(int i=0;i<Q;i++){
        getpoint(hand.at(i).first,hand.at(i).second);
    }
    for(int i=1;i<=N;i++)cout<<point.at(i)<<" ";
    cout<<endl;
}