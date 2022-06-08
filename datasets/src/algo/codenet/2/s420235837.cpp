#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{   
    int N;
    ll Ai;
    multimap<ll,ll,greater<ll>> A;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> Ai;
        auto ai = Ai;
        
        ll tmp = 1; 
        while( ai > 0 ){ tmp <<= 1; ai >>= 1; }
        A.emplace(Ai, tmp-Ai);
    }
    int n=0; 
    for(auto itr =A.begin(); itr!=A.end(); itr++){
        auto itr2 = A.find(itr->second);
        if(itr2 == A.end()) continue;
        if(itr2 == itr) continue;
        n++;
        A.erase(itr2);
        A.erase(itr);
        itr--;
    }
    
    cout<<n<<endl;
    
    return 0;
}