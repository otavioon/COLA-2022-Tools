#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

#define rep(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define rrep(i,a,n) for(int (i)=(a);(i)>=(n);(i)--)

#define INF 10000000

typedef  long long ll;

using namespace std;

double euclid_distance(double a,double b){
    return sqrt(a*a+b*b);
}

int gcd(long long int a,long long int b){
    long long int r;
    if(a < b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

void Integer_factorization(long long int b,long long int n){
    long long int a = 2;
    long long int count = 0;
    long long int ans = 1;
    long long int ndash = n;
    if(b == 1) cout << n << endl;
    else{
    while(ndash >= a*a){
        if(n % a  == 0){
            count++;
            n/=a;

        if(count % b == 0){
            ans *= a;
        }
        }else{a++;count = 0;}
    }

    cout<<  ans << endl;
    }
}

void ys(){
    cout << "Yes" << endl;
}

void yb(){
    cout << "YES" << endl;
}

void ns(){
    cout << "No" << endl;
}

void nb(){
    cout << "NO" << endl;
}
//A 3min
//B 45min(sortを実装しようとしたところミスがでた)
string ans;
int order(int n){
    int o=0;
    while(n > 1){
        if(n == 10){
            o+=2;
            break;
        }
        n/=10;
        o++;
    }
    return o;
}

void solve(void){
    int n,k;
    cin >> n >> k;
    int d[k];
   
    rep(i,0,k) cin >> d[i];
    int o = order(n);
    bool flag;
    
    rep(i,n,10*n+1){
        int tmp = i;
        rep(j,0,o){
            flag = false;
            rep(ia,0,k){
                if(tmp%10 == d[ia]){
                    flag  =true;
                    break;
                }
            }
            if(flag) break;
            tmp/=10;
        }
    if(tmp < 10 && !flag) tmp/=10;
        if(tmp == 0){
            cout << i << endl;
            return;
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}