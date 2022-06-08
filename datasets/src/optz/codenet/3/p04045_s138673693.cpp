//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N,K;
    cin>>N>>K;
    vector<int> dk(K);
    unordered_set<int> dis;
    for(auto&& d:dk){
        cin>>d;
		dis.insert(d);
	}
    auto check_func=[&](int val){
        while(val > 0){
            if(dis.count(val%10)>0)return false;
            val /= 10;
        }
        return true;
    };
    while(!check_func(N)){ //全探索
		++N;
	}
    cout<<N<<endl;
    return 0;
}