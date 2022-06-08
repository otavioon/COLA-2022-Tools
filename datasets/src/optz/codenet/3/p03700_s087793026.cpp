#include<iostream>
#include<list>
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std;

int countAttackNum(list<int> lst,int a,int b){
    int counter = 0,tmp;
    while(1) {
        lst.sort();
        if (lst.back() <= 0)return counter;
        auto itr = lst.end();
        itr--;
        tmp = ((lst.back() - *itr)/(a-b))+1;
        if(tmp == 0)tmp = 1;
        for(auto itr = lst.begin();itr != lst.end();++itr){
            *itr -= tmp*b;
        }
        lst.back() -= tmp * (a-b);
        counter += tmp;
    }
}

int main(){
    list<int> lst;
    int n,a,b,h,ans;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        cin >> h;
        lst.push_back(h);
    }
    ans = countAttackNum(lst,a,b);
    cout << ans << endl;
    return 0;
}