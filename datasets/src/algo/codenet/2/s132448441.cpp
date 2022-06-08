#include<iostream>
#include<set>
using namespace std;

int main(){
    int N;
    cin>>N;
    multiset<int> s;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    int pow2[31];pow2[0]=1;
    for(int i=1;i<31;i++){
        pow2[i]=pow2[i-1]*2;
    }
    int ans=0;
    while(!s.empty()){
        multiset<int>::iterator it=s.end(); it--;
        int X=*it;
        s.erase(it);//自分は削除
        int tmp;
        for(int j=0;j<31;j++){
            if(X<pow2[j]){
                tmp=pow2[j]-X;
                break;
            }
        }
        multiset<int>::iterator it2=s.find(tmp);
        if(it2 != s.end()){//見つかった
            ans++;
            s.erase(it2);//ペアも削除
        }
    }
    cout<<ans<<endl;
    return 0;
}
