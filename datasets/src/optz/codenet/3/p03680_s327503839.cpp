#include<iostream>
#include<deque>


using namespace std;

int main(){
    long N;
    cin>>N;

    deque<long> dec(N);

    for(auto &x:dec){
        cin>>x;
    }

    long i=1;
    long tmp=1;

    long ans=0;
    while(1){
        if(i==2){
            cout<<ans<<endl;
            return 0;
        }else if(i==1e9+7){
            cout<<-1<<endl;
            return 0;

        }else{
            ans++;
            tmp=i;
            i=dec[i-1];
            dec[tmp-1]=1e9+7;
        }


    }



}