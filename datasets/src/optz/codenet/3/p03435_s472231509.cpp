#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vvvi = vector<vvi>;
using ll = long long; //long longをllだけにした
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll =vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using mii = map<int,int>;

long long divup(long long a,long long b);
long long kaijou(long long i);
long long P(long long n,long long k);
long long C(long long n,long long k);
long long GCD(long long a,long long b);
long long LCM(long long a,long long b);
bool prime (long long N);
double distance(vector<long long>p,vector<long long>q,long long n);

void press(vector<long long> &v);
void ranking(vector<long long> &v);
void erase(vector<long long> &v,long long i);
void unique(vector<long long> &v);
void printv(vector<long long> v);

vector<ll> keta(ll x);


long long modpow(long long a, long long n, long long mod);
long long modinv(long long a, long long mod);

//20200416
vector<long long> inputv(long long n);

//20200417
vector<long long> yakusuu(int n);
map<long long,long long> soinsuu(long long n);
vector<vector<long long>> maze(long long i,long long j,vector<string> &s);


//////////////////////////////////////////////////////

//端数繰りあがり割り算(検証済)
//a÷bの端数繰り上げ
//b!=0のデバグはしてないので分母に0を入れないように
//負数対応
long long divup(long long a,long long b){
    long long x=abs(a);
    long long y=abs(b);
    long long z = (x+y-1)/y;
    if((a<0&&b>0)||(a>0&&b<0)) return -z;
    else if(a==0) return 0;
    else return z;
}

//階乗
//検証済み
long long kaijou(long long i){
    if(i==0) return 1;
    long long j=1;
    for(long long k=1;k<=i;k++){
        j*=k;
    }
    return j;
}

//順列nPk(完成)
//n個の異なる要素から、取り出す順序を区別してk個取り出す場合の数
//n<kなら0を返す
//敢えて負数時のデバグはしてない
long long P(long long n,long long k){
    if(n<k) return 0;
    long long y=1;
    for(long long i=0;i<k;i++){
        y*=(n-i);
    }
    return y;
}
//組み合わせnCk(検証済み)
//P,kaijouと併用
long long C(long long n,long long k){
    if(n<k) return 0;
    return P(n,k)/kaijou(k);
}
//nHk
//区別しないn個の要素を、区別するk個のグループに分ける
//0個のグループがあっ
//て良い
//C必須

//最大公約数GCD,最小公倍数LCM
//LCMを使うときはGCDをセットで
//検証済み
long long GCD(long long a,long long b){
    if(a<b) swap(a,b);
    long long d=a%b;
    if(d==0){
        return b;
    }
    return GCD(b,d);
}
long long LCM(long long a,long long b){
    return (a/GCD(a,b))*b;
}

//素数判定
//素数ならばtrue、素数以外の整数にはfalse
//負数は全てfalse
//検証済み
bool prime (long long N){
    if(N==1){
        return false;
    }
    if(N<0) return false;
    long long p=sqrt(N);
    for(long long i=2;i<=p;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

//ユークリッド距離
//検証済み
//位置ベクトル1,位置ベクトル2,ベクトルの次元(2または3が一般的)
double distance(vector<long long>p,vector<long long>q,long long n){
    double x=0;
    for(long long i=0;i<n;i++){
        x+=pow((p.at(i)-q.at(i)),2);
    }
    return sqrt(x);
}


//配列圧縮(検証済)
//{1,36,1,3,8,-2,-92}を
//{2, 5,2,3,4, 1,  0}にする
void press(vector<long long> &v){
    long long n=v.size();
    vector<long long> w(n);
    map<long long,long long> m;
    for(auto &p:v){
        m[p]=0;
    }
    long long i=0;
    for(auto &p:m){
        p.second=i;
        i++;
    }
    for(long long i=0;i<n;i++){
        w.at(i)=m[v.at(i)];
    }
    v=w;
    return;
}

//配列のi番目の要素がj番目に小さいとき、j番目の数がiであるベクトルを返す関数
//配列の要素が全て異なるときにしか正常に動作しない
//配列の要素に同じものが含まれても見かけ上動作はするが意味のない値を戻し、
//エラーも起きないので注意
//検証済
//{2,4,1,6,0,3,8,9,5}を
//{4,2,0,5,1,8,3,6,7}にして返す
//"rank"という名前にするとSTLの関数(配列の次元を返す関数)になるので注意
void ranking(vector<long long> &v) {
    long long n=v.size();
    map<long long,long long> m;
    long long i;
    for(i=0;i<n;i++){
        m[v.at(i)]=i;
    }
    vector<long long> w(n);
    i=0;
    for(auto &p:m){
        v.at(i)=p.second;
        i++;
    }
    return;
}

//部分削除(未検証)
//ベクトルのi番目(i=0,1,2,...,n-1)の要素を削除し、
//以降の要素を全て前に1ずらして参照返し
//ベクトル長は1小さくなって返る
//i>n-1の時は変化しない
void erase(vector<long long> &v,long long i){
    long long n=v.size();
    if(i>n-1) return;
    for(long long j=i;j<n-1;j++){
        v.at(j)=v.at(j+1);
    }
    v.pop_back();
    return;
}

//重複削除(未完成)
//引数ベクトルに同一要素が複数あるとき、先頭を残し他は削除
//参照返し
//ベクトル長も変化する
//O(logn)くらい
void unique(vector<long long> &v){
    long long n=v.size();
    set<long long> s;
    long long i=0;
    while(i<n){
        if(s.count(v.at(i))){
            erase(v,i);
            n--;
        }else{
            s.insert(v.at(i));
            i++;
        }
    }
    return;
}

//ベクトルの出力(検証済)
//debug用にvectorの中身を出力する
void printv(vector<long long> v){
    cout<<"{ ";
    for(auto &p:v){
        cout<<p<<",";
    }
    cout<<"}"<<endl;
}



//10進法でn桁の整数xに対して、大きい方の位から、その位の1桁の数字を
//収納した長さnのベクトルを返す
//0に対しては{0}を返す
//検証済み
vector<ll> keta(ll x){
    if(x==0) return {0};
    ll n=log10(x)+1;//xの桁数
    vll w(n,0);
    for(ll i=0;i<n;i++){
        ll p;
        p=x%10;
        x=x/10;
        w[n-1-i]=p;
    }
    return w;
}


//20200415
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
//modとaが互いに素のときのみ有効(数学的に逆元が一意に定まるのがそのときのみ)
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}



//整数n個の入力を受け取ってベクトルに突っ込んで返す
//チェック済み
vector<long long> inputv(long long n){
    vector<long long> v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    return v;
}


vector<long long> yakusuu(long long n)//nの約数を列挙
{
	vector<long long> ret;
	for(long long i=1 ; i<=sqrt(n) ; ++i)
	{
		if(n%i == 0)
		{
			ret.push_back(i);
			if(i*i!=n)
			{
				ret.push_back(n/i);
			}
		}
	}
    sort(ret.begin(),ret.end());
	return ret;
}


map<long long,long long> soinsuu(long long n){
    map <long long,long long> m;
    long long p=sqrt(n);
    while(n%2==0){
        n/=2;
        if(m.count(2)){
            m[2]++;
        }else{
            m[2]=1;
        }
    }
    for(long long i=3;i*i<=n;i+=2){   
        while(n%i==0){
            n/=i;
            if(m.count(i)){
                m[i]++;
            }else{
                m[i]=1;
            }
        }
    }
    if(n!=1) m[n]=1;
    return m;
}




//スタートが(i,j)の迷路の全ての地点までの距離を幅優先探索で解く
//スタートから何マス離れているか(辿り着けない場合は-1)を入れたベクトルを返す
//壁からスタートしても正常に動作するので注意(この関数の外で処理が必要)
//検証済み 一応O(地図の広さ)くらい
vector<vector<long long>> maze(ll i,ll j,vector<string> &s){
    ll h=s.size();
    ll w=s[0].size();
    queue<vector<long long>> q;
    vector<vector<long long>> dis(h,vll(w,-1));
    q.push({i,j});
    dis[i][j]=0;
    while(!q.empty()){
        auto v=q.front();
        q.pop();
        if(v[0]>0 && s[v[0]-1][v[1]]=='.' && dis[v[0]-1][v[1]]==-1){
            dis[v[0]-1][v[1]]=dis[v[0]][v[1]]+1;
            q.push({v[0]-1,v[1]});
        }
        if(v[1]>0 && s[v[0]][v[1]-1]=='.' && dis[v[0]][v[1]-1]==-1){
            dis[v[0]][v[1]-1]=dis[v[0]][v[1]]+1;
            q.push({v[0],v[1]-1});
        }
        if(v[0]<h-1 && s[v[0]+1][v[1]]=='.' && dis[v[0]+1][v[1]]==-1){
            dis[v[0]+1][v[1]]=dis[v[0]][v[1]]+1;
            q.push({v[0]+1,v[1]});
        }
        if(v[1]<w-1 && s[v[0]][v[1]+1]=='.' && dis[v[0]][v[1]+1]==-1){
            dis[v[0]][v[1]+1]=dis[v[0]][v[1]]+1;
            q.push({v[0],v[1]+1});
        }
    }
    return dis;//スタートから何マス離れているか(辿り着けない場合は-1)
}


//エラトステネスのふるいによりn以下の素数を全てベクトルに入れて返す
// vector<long long> eratos(long long n){
// }



//二項係数の剰余を求める
//引数は剰余の形ではなくもとの数そのものである
//未検証(検証サンプルがない)
long long modC(long long n,long long k,long long mod){
    if(n<k) return 0;
    long long p=1,q=1;
    for(long long i=0;i<k;i++){
        p = p*(n-i-1)%mod;
        q = q *(i+1)%mod;
    }
    return p*modinv(q,mod)%mod;
}


//20200418
// 整数のとき限定の普通のPOW関数
//標準機能のpow(a,n)は整数だとバグるのでこちらを使う
long long POW(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}


//cout<<fixed<<setprecision(10);
//////////////////////////////////////////////////




int main(){
    auto c=inputv(9);
    ll p=c[0]-c[3];
    bool b=true;
    if(c[1]-c[4]==c[2]-c[5]&&p==c[1]-c[4]){
    }else{
        b=false;
    }
    
    ll q=c[6]-c[3];
    if(c[7]-c[4]==c[8]-c[5]&&q==c[7]-c[4]){
    }else{
        b=false;
    }
    if(b) cout<<"Yes";
    else cout<<"No";
    
}

