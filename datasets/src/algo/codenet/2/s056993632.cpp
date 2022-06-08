#include <iostream>
#include<algorithm>
#include<vector> //動的配列
#include<string> 
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>


//小さい順から取り出すヒープ
//priority_queue<ll, vector<ll>, greater<ll> > pque1;

typedef long long ll;


using namespace std;

typedef pair<int, int> P;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int n;


int main(){
    cin>>n;
    multiset<int> l;
    int a;
    for (int i=0;i<n;i++){
        cin>>a;
        l.insert(a);
    }
    int ans=0;
    while (l.empty()==false){
        auto itr=l.end();
        itr--;
        int x=*itr;
        //cout<<x;
        l.erase(itr);
        int j=1;
        while(j<=x){
            j*=2;
        }
        int pairx=j-x;
        //cout<<pairx<<endl;
        if (l.count(pairx)!=0){
            auto itr2=l.find(pairx);
            l.erase(itr2);
            ans+=1;
        }
    }
    cout<<ans<<endl;
}
