#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(ll i##_len=(n) ,i=i##_len-1;i>=0;--i)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define printd(val) std::cout<< #val" = " <<val<<"\n";
#define printv(val) std::for_each(val.begin(),val.end(),[](auto x){cout<<x<<"\n";});
#define ALL(f,x,...) ([&](decltype((x)) xxxx) { return (f)(begin(xxxx), end(xxxx), ## __VA_ARGS__); })(x)
#define lim 1000000007ll
#include<bits/stdc++.h>
using ll = long long;
using pii = std::pair<ll,ll>;
using namespace std;
template<class T>T 
chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>T 
chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template <class T> T 
gcd(T a, T b){if (a < b) {a ^= b;b ^= a;a ^= b;} return b ? gcd(b, a % b) : a;}
template <class T> T 
lcm(T a, T b){return a * b / gcd(a, b);}
inline bool 
operator<(const pii &lhs,const pii &rhs){return(lhs.second<rhs.second);}
vector<char> 
string_to_vector_char(const string& input){vector<char> out(input.length());rep(i,input.length()){out[i]=input[i];}return out;}
vector<int> 
string_to_vector_int(const string& input){vector<int> out(input.length());rep(i,input.length()){out[i] = (int)(input[i]-'0');} return out;}
map<int,int> 
count_same_elements(const vector<int>& v){map<int,int>cmap; for_each(v.begin(),v.end(),[&cmap](int x){cmap[x]++;}); return cmap; }
map<char,int> 
count_same_elements(const vector<char>& v){map<char,int>cmap; for_each(v.begin(),v.end(),[&cmap](int x){cmap[x]++;}); return cmap; }
template<class A,class B> vector<B> 
mapf(const vector<A>& v,const function<B(A)>& func){vector<B> v_(v.size());rep(i,v.size()){ v_[i]=func(v[i]); }return v_;}
template<class A,class B> vector<B> 
adjacent_map(const vector<A>& v,const function<B(A,A)>& func){vector<B> v_(v.size()-1);rep(i,v.size()-1){ v_[i]=func(v[i+1],v[i]); }return v_;}
template<class A,class B> vector<B> 
tryple_map(const vector<A>& v,const function<B(A,A,A)>& func){vector<B> v_(v.size()-2);rep(i,v.size()-2){ v_[i]=func(v[i+2],v[i+1],v[i]); }return v_;}
template<class A,class B> vector<B> 
mapf(const vector<A>& v,const B& (*func)(A)){vector<B> v_(v.size());rep(i,v.size()){ v_[i]=func(v[i]); }return v_;}
template<class A,class B> vector<B> 
adjacent_map(const vector<A>& v,B (*func)(A,A)){vector<B> v_(v.size()-1);rep(i,v.size()-1){ v_[i]=func(v[i+1],v[i]); }return v_;}
template<class A,class B> vector<B> 
tryple_map(const vector<A>& v,B (*func)(A,A,A)){vector<B> v_(v.size()-2);rep(i,v.size()-2){ v_[i]=func(v[i+2],v[i+1],v[i]); }return v_;}
template<class T,class U>
void msg_with_compare(T A,T B,U A_greater_B,U A_eq_B,U A_less_B){
    if(A==B){cout<<A_eq_B<<"\n";}else if(A>B){cout<<A_greater_B<<"\n";}else{cout<<A_less_B<<"\n";}}
template<class B,class T>
void msg_with_boolean(B A,T true_msg,T false_msg){
    cout<< ( A? true_msg:false_msg);}
template<class B,class T>
void msg_with_boolean(B A1,B A2,T both_true_msg,T true_false_msg,T false_true_msg,T both_false_msg){
    if(A1){if(A2){cout<<both_true_msg;}else{cout<<true_false_msg;}
    }else{if(A2){cout<<false_true_msg;}else{cout<<both_false_msg;}}
}
int twosame(int a,int b){return a==b;}
int tryple_same(int a,int b,int c){return a==b and b==c;}
int integer_sumnation(int a,int b){return a+b;}

ll n,k,a,b,c,d,x;
vector<ll>v;
string s;
void input(){
    cin>>n;
}
void src(){
    msg_with_boolean(n%2==0,n,n*2);
}

int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
 //   ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
    return 0;
}