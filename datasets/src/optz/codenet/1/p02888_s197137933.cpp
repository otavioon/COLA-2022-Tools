#include <bits/stdc++.h>
// created [2019/11/10] 19:32:29
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using uint = unsigned int;
using usize = std::size_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T> constexpr T popcount(const T u) { return u ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T log2p1(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T msbp1(const T u) { return log2p1(u); }
template<typename T> constexpr T lsbp1(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? log2p1(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool ispow2(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (log2p1(u) - 1); }
template<typename T> constexpr bool btest(const T mask, const usize ind) { return static_cast<bool>((static_cast<u64>(mask) >> ind) & static_cast<u64>(1)); }
template<typename T> void bset(T& mask, const usize ind) { mask |= (static_cast<T>(1) << ind); }
template<typename T> void breset(T& mask, const usize ind) { mask &= ~(static_cast<T>(1) << ind); }
template<typename T> void bflip(T& mask, const usize ind) { mask ^= (static_cast<T>(1) << ind); }
template<typename T> void bset(T& mask, const usize ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> constexpr T bcut(const T mask, const usize ind) { return ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(mask) << (64 - ind)) >> (64 - ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};

template<typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template<typename T, typename... Args>
auto read(const usize size, Args... args)
{
    std::vector<decltype(read<T>(args...))> ans(size);
    for (usize i = 0; i < size; i++) { ans[i] = read<T>(args...); }
    return ans;
}
template<typename... Types>
auto reads() { return std::tuple<std::decay_t<Types>...>{read<Types>()...}; }
#    define SHOW(...) static_cast<void>(0)
template<typename T>
T make_v(const T v) { return v; }
template<typename... Args>
auto make_v(const std::size_t size, Args... args) { return std::vector<decltype(make_v(args...))>(size, make_v(args...)); }
int main()
{
    const auto n        = read<usize>();
    constexpr usize MAX = 1000;
    std::vector<usize> num(MAX + 1, 0);
    for (usize i = 0; i < n; i++) { num[read<usize>()]++; }
    auto sum = num;
    for (int i = (int)MAX - 1; i >= 0; i--) { sum[i] += sum[i + 1]; }
    ll ans = n * (n - 1) * (n - 2) / 6;
    for (usize i = 1; i <= MAX; i++) {
        for (usize j = i; j <= MAX; j++) {
            const ll c2 = (i == j ? num[i] * (num[i] - 1) / 2 : num[i] * num[j]);
            if (i + j <= MAX) { ans -= c2 * sum[i + j]; }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
