#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT_ON(bit, i) (((bit >> i) & 1) > 0)

typedef long long LL;
template<typename T> std::vector<T> make_v(size_t a){return std::vector<T>(a);}
template<typename T,typename... Ts> auto make_v(size_t a, Ts... ts){ return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}    // C++14
template<typename T,typename V> typename std::enable_if<std::is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename std::enable_if<std::is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
template<class T> inline T ceil(T a, T b) { return (a + b - 1) / b; }
template<class T> inline void print(T x) { std::cout << x << std::endl; }
template<class T> inline void print_vec(const std::vector<T> &v) { for (int i = 0; i < v.size(); ++i) {  if (i != 0) {std::cout << " ";} std::cout << v[i];} std::cout << "\n"; }
template<class T> inline bool inside(T y, T x, T H, T W) {return 0 <= y and y < H and 0 <= x and x < W; }
template<class T> inline double euclidean_distance(T y1, T x1, T y2, T x2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
template<class T> inline double manhattan_distance(T y1, T x1, T y2, T x2) { return abs(x1 - x2) + abs(y1 - y2); }
template<typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }

template<class T> inline std::vector<T> unique(std::vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}
// 初項s, 交差dのn個の数列の和
long long sum_of_arithmetic_progression(long long s, long long d, long long n) {
    return n * (2 * s + (n - 1) * d) / 2;
}

const int INF = 1 << 30;
const double EPS = 1e-9;
const long double PI = acos(-1.0);
const std::vector<int> dy4 = {0, -1, 0, 1}, dx4 = {1, 0, -1, 0};
const std::vector<int> dy8 = { 0, -1, 0, 1, 1, -1, -1, 1 }, dx8 = { 1, 0, -1, 0, 1, 1, -1, -1 };


using namespace std;

template<class T> class BisectWrapper {
public:
    // aにxが存在するか
    bool exist(const std::vector<T> &a, int x) {
        return binary_search(a.begin(), a.end(), x);
    }

    // xのindex(なければ-1)
    int index(const std::vector<T> &a, int x) {
        auto i = lower_bound(a.begin(), a.end(), x);
        if (i != a.end() and a[i] == x) {
            return distance(a.begin(), i);
        }
    }

    // y < xのようなyの中でもっとも右のindex
    int index_lt(const std::vector<T> &a, int x) {
        auto i = lower_bound(a.begin(), a.end(), x);
        return distance(a.begin(), i) - 1;
    }

    // y < xのようなyの個数
    int num_lt(const std::vector<T> &a, int x) {
        return this->index_lt(a, x) + 1;
    }

    // y <= xのようなyの中でもっとも右のindex
    int index_lte(const std::vector<T> &a, int x) {
        return -1;
    }

    // y <= xのようなyの個数
    int num_lte(const std::vector<T> &a, int x) {
        return -1;
    }

    // y > xのようなyの中でもっとも左のindex
    // なければN
    int index_gt(const std::vector<T> &a, int x) {
        auto i = upper_bound(a.begin(), a.end(), x);
        return distance(a.begin(), i);
    }

    // y > xのようなyの個数
    int num_gt(const std::vector<T> &a, int x) {
        return a.size() - this->index_gt(a, x);
    }

    // y >= xのようなyの中でもっとも左のindex
    int index_gte(const std::vector<T> &a, int x) {
        return -1;
    }

    // y >= xのようなyの個数
    int num_gte(const std::vector<T> &a, int x) {
        return -1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    auto A = make_v<LL>(N);
    auto B = make_v<LL>(N);
    auto C = make_v<LL>(N);
    FOR(i, 0, N) {
        cin >> A[i];
    }
    FOR(i, 0, N) {
        cin >> B[i];
    }
    FOR(i, 0, N) {
        cin >> C[i];
    }
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    LL ans = 0;
    BisectWrapper<LL> bw;
    FOE(b, B) {
        LL a = bw.num_lt(A, b);
        LL c = bw.num_gt(C, b);
        ans += a * c;
    }
    print(ans);


    return 0;
}

