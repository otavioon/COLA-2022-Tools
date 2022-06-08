#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string S;
    long K;
    cin>>S>>K;
    int size = S.size();
    S += S + S + S;
    long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for(int i=1;i<size;++i){
        if(S[i]==S[i-1]){
            ans1++;
            S[i] = '*';
        }
    }
    for(int i=size;i<size*2;++i){
        if(S[i]==S[i-1]){
            ans2++;
            S[i] = '*';
        }
    }
    for(int i=size*2;i<size*3;++i){
        if(S[i]==S[i-1]){
            ans3++;
            S[i] = '*';
        }
    }
    for(int i=size*3;i<size*4;++i){
        if(S[i]==S[i-1]){
            ans4++;
            S[i] = '*';
        }
    }
    if(K==1)cout<<ans1<<endl;
    else if(K==2)cout<<ans1+ans2<<endl;
    else if(K%2==0)cout<<ans1+ans4+(K-2)/2*ans2+(K-2)/2*ans3<<endl;
    else cout<<ans1+ans4+((K-2)/2+1)*ans2 + ((K-2)/2)*ans3<<endl;
}
