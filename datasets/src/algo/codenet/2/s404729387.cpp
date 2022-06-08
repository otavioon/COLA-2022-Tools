#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N;
    int a;multiset<int> A;
    cin >> N;
    REP(i,N){
        cin >> a;
        A.insert(a);
    }
    int Ans=0;
    while(A.size()>=2){
        decltype(A)::iterator it = A.end();
        it--;
        int p=*it;
        A.erase(p);
        int K=(int)pow(2,(int)log2(p));
        K*=2;
        decltype(A)::iterator it2= A.find(K-p);
        if(it2 != A.end()){
            Ans++;
            A.erase(*it2);
        }
        /*
        decltype(A)::iterator it3 = A.begin();
        while(it3!=A.end()){
            cout << *it3 << " ";
            it3++;
        }cout << endl;*/
    }
    cout << Ans << endl;
    return 0;
}

