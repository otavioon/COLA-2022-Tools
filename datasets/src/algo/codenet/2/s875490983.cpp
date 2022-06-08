#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int N;
    int A[200000];
    cin>>N;
    multiset<int> s;
    for(int i=0;i<N;i++){
        cin>>A[i];
        s.insert(A[i]);
    }
    //sort(A,A+N);
    int pow2[31];pow2[0]=1;
    for(int i=1;i<31;i++){
        pow2[i]=pow2[i-1]*2;
    }
    //bool IsUsed[200000]={};
    int ans=0;
    while(!s.empty()){
        multiset<int>::iterator it=s.end(); it--;
        int X=*it;
        s.erase(it);//自分は削除
        //cout<<X<<endl;
        int keta,tmp;
        for(int j=0;j<31;j++){
            if(X<pow2[j]){
                keta=j;
                tmp=pow2[j]-X;
                break;
            }
        }
        multiset<int>::iterator it2=s.find(tmp);
        if(it2 != s.end()){//見つかった
            ans++;
            s.erase(it2);
        }
        
        /*
        //A[i]の位置を知る．
        if(!IsUsed[i]){
            IsUsed[i]=true;
            int keta;
            for(int j=0;j<31;j++){
                if(A[i]<pow2[j]){
                    keta=j;
                    break;
                }
            }
            //2^jを作れるか試す．
            int tmp=pow2[keta]-A[i];
            int* p=upper_bound(A,A+N,tmp);
            int X=(int)(p-A);
            X--;
            if(X>=0 && A[X]==tmp){
                if(X!=i){
                    IsUsed[X]=true;
                    ans++;
                }else if(X-1>=0 && A[X-1]==tmp){
                    IsUsed[X-1]=true;
                    ans++;
                }
            }
        }*/
    }
    cout<<ans<<endl;
    return 0;
}
