#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = long long;
using P = std::tuple<ll,ll>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int N;
int A[200100];
std::vector<P> B;

ll rmb(int n){
    ll res = 0;
    while(n > 0){
        res = n & -n;
        n -= n & -n;
    }
    return res;
}

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(int i=0;i<N;++i){
        std::cin >> A[i];
    }

    std::sort(A, A+N);

    for(int i=0,j=0;i<N;i=j){
        while(j < N && A[j] == A[i]){
            ++j;
        }

        B.emplace_back(A[i], j - i);
    }

    int M = B.size();
    int res = 0;
    for(int i=M-1;i>=0;--i){
        ll a1, c1;
        std::tie(a1, c1) = B[i];

        ll sum = rmb(a1) * 2;
        int j = std::lower_bound(B.begin(), B.end(), std::make_tuple(sum - a1, -1)) - B.begin();

        if(j >= M || a1 + fst(B[j]) != sum){
            continue;
        }

        if(j == i){
            res += c1 / 2;
        }else{
            int n = std::min(c1, snd(B[j]));
            res += n;
            snd(B[j]) -= n;
        }
    }

    std::cout << res << std::endl;
}
