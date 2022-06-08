#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <typeinfo>
#include <queue>
#include <set>
#include <sstream>

using namespace std;

#define RSORT(c) sort((c).begin(),(c).end(),std::greater<int>())
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SORT(c) sort((c).begin(),(c).end())

static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
#define MAX 200000
#define SENTINEL 10000000000
typedef long long ll;


void c1(){
  int l = 10;
  string s;
  cin >> s;
  //s[4] = "8";
  s.replace(3, 1, "8");
  cout << s << endl;
}

void c2(){
  int n;
  cin >> n;
  int tmp;
  vector<int> vec;
  REP(i,n){
    cin >> tmp;
    vec.push_back(tmp);
  }
  SORT(vec);
    //erace(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  cout << vec.size() << endl;
}

void c3(){
  int n;
  int m;
  cin >> n;
  cin >> m;
  int x,y,z;
  x=y=z=0;
  bool xf,yf,zf;
  xf=true;
  yf=zf=false;
  int now=0;
  REP(i,n){
    if(xf == true){
      if(now + 10000 > m){
        xf = false;
        yf=true;
      }
      else{
        x++;
        now += 10000;
      }
    }
    if(yf == true){
      if(now + 5000 > m){
        yf = false;
        zf=true;
      }
      else{
        y++;
        now += 5000;
      }
    }
    if(zf == true){
      if(now + 1000 > m){
        zf = false;
        break;
      }
      else{
        z++;
        now += 1000;
      }
    }
  }
  int ss = 0;
  ss = x+y+z;
  //cout << x << y << z << endl;
  //cout << ss << endl;
  bool dame = false;
  if (now < m){
    dame=true;
    //cout << -1 << " " <<  -1 << " " << -1;
  }
  int amari = n - ss;
  yf=true;
  xf=zf=false;
  if(x>0){
    y+=2*x;
    amari-=x;
    x=0;
  }
  while(amari > 0){
    if(xf){
      if(x - amari> 0){
        int diff=x-amari;
        x-= amari;
        y+=2*diff;
        amari=0;
        //cout << "a";
        //cout <<  "a";
      }
      else{
        xf=false;
        //yf=true;
        //dame=true;
        break;
      }
    }
    //cout <<"a" <<  amari << endl;
    if(yf){
      if(y>0 && amari > 3){
        int sho = amari / 4;
        int wei = amari % 4;
        y-=sho;
        z+=5*sho;
        amari-=4*sho;
      }
      else{
        yf=false;
        xf=true;
        //break;
        //dame=true;
        //break;
      }
    }
                   //cout << "b" << amari << endl;
  }
  if (amari > 0 && dame == false){
    if(amari==2){
      x+=2;
      y-=5;
      z+=5;
    }
    else{
      x+=1;
      y-=3;
      z+=5;
    }
    }
    //dame=false;
  if (dame==true){
    cout << -1 << " " <<  -1 << " " << -1 << endl;
  }
  else{
    cout << x << " " <<  y << " " << z << endl;
  }
}

void c4(){
  int n;
  int m;
  cin >> n;
  cin >> m;
  int x,y,z;
  x=y=z=0;
  bool xf,yf,zf;
  xf=true;
  yf=zf=false;
  int now=0;
  REP(i,n){
    if(xf == true){
      if(now + 10000 > m){
        xf = false;
        yf=true;
      }
      else{
        x++;
        now += 10000;
      }
    }
    if(yf == true){
      if(now + 5000 > m){
        yf = false;
        zf=true;
      }
      else{
        y++;
        now += 5000;
      }
    }
    if(zf == true){
      if(now + 1000 > m){
        zf = false;
        break;
      }
      else{
        z++;
        now += 1000;
      }
    }
  }
  int ss = 0;
  ss = x+y+z;
  //cout << x << y << z << endl;
  //cout << ss << endl;
  bool dame = false;
  int xn,yn,zn;
  if (now < m){
    dame=true;
    //cout << -1 << " " <<  -1 << " " << -1;
  }
  else{
    //int nokori= n - ss;
    //int sho = nokori/4;
    //int amari =nokori%4;
    zn = m / 1000;
    //int xn,yn;
    xn=yn=0;
    while(zn +yn >= n && zn >= 0){
      zn-=5;
      yn+=1;
    }
    //if (zn<0){
      zn+=5;
      yn--;
      //}
      int diff=n-zn;
      while(yn + xn >= diff && yn >= 0){
        yn-=2;
        xn+=1;
      }
      //cout << xn << " " << yn << " " << zn << endl;
        yn+=2;
        xn--;
      if( xn + yn + zn != n){
        dame = true;
      }
    }
  if (zn*1000 + yn*5000 + xn*10000 != m){
    dame =true;
  }
  if (dame==true){
    cout << -1 << " " <<  -1 << " " << -1 << endl;
  }
  else{
    cout << xn << " " <<  yn << " " << zn << endl;
  }
}

void c5(){
  int n,m;
  cin >> n >> m;
  bool dame = false;
  int xn,yn,zn;
    //int nokori= n - ss;
    //int sho = nokori/4;
    //int amari =nokori%4;
    zn = m / 1000;
    //int xn,yn;
    xn=yn=0;
    while(zn +yn >= n && zn >= 0){
      zn-=5;
      yn+=1;
    }
    //if (zn<0){
    zn+=5;
    yn--;
    //}
    int diff=n-zn;
    while(yn + xn >= diff && yn >= 0){
      yn-=2;
      xn+=1;
    }
    //cout << xn << " " << yn << " " << zn << endl;
    yn+=2;
    xn--;
    if( xn + yn + zn != n){
      dame = true;
    }
  if (zn*1000 + yn*5000 + xn*10000 != m){
    dame =true;
  }
  if (dame==true){
    cout << -1 << " " <<  -1 << " " << -1 << endl;
  }
  else{
    cout << xn << " " <<  yn << " " << zn << endl;
  }
  
}

void c6(){
  int n,h;
  cin >> n >> h;
  vector<int> a,b,vec;
  int tmp1,tmp2;
  REP(i,n){
    cin >> tmp1 >> tmp2;
    a.push_back(tmp1);
    b.push_back(tmp2);
    vec.push_back(tmp1);
    vec.push_back(tmp2);
  }
  //pairの入ったvectorの定義
  typedef std::pair<int, int> pair;
  std::vector<pair> pair_vec;

  //pair入りvectorに添字とvectorの中身を挿入
  //std::cout << "before sort" << std::endl;
  for(int i=0; i<vec.size(); i++){
    pair_vec.push_back(pair(i, vec[i]));
    //std::cout << i << " " << vec[i] << std::endl;
  }

  //ラムダ式で比較式を書く
  std::sort(
            pair_vec.begin(),
            pair_vec.end(),
            [](const pair& x, const pair& y){return x.second > y.second;}
            );

  // std::cout << "before sort" << std::endl; 
  // for(auto& i:index){
  //  std::cout << i << " " << vec[i] << std::endl;
  // }
  int num=0;
  int attacker=0;
  for(auto& i: pair_vec){
    h-=i.second;
    num++;
    //std::cout << i.first << " " << i.second << std::endl;

    if(i.first%2 == 0){
      attacker=i.second;
      break;
    }
    if(h<=0){
      break;
    }
  }

  if(h<=0){
    cout << num << endl;
  }
  else{
    int sho = h / attacker;
    int amari = h % attacker;
    if(amari > 0){
      sho++;
    }
    cout << num + sho << endl;
  }


}

void c7(){
  int n,a;
  cin >> n >> a;
  int sho,amari;
  amari = n % 500;
  if(amari == 0){
    cout << "Yes" << endl;
  }
  else{
    if(amari <= a){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
}

void c8(){
  int n;
  cin >> n;
  vector<int> vec;
  int tmp;
  REP(i,n){
    cin >> tmp;
    vec.push_back(tmp);
  }
  RSORT(vec);
  int ali=0;
  int bob=0;
  REP(i,n){
    //cout << vec[i] << endl;
    if(i%2==0){
      ali+=vec[i];
    }
    else{
      bob+=vec[i];
    }
  }
  cout << ali-bob << endl;

}

void c9(){
  vector<int> c;
  int tmp;
  REP(i,9){
    cin >> tmp;
    c.push_back(tmp);
  }
  //vector<int> a,b;
  int a[3],b[3];
  a[0] = 0;
  b[0] = c[0] - a[0];
  int val;
  b[1] = c[1] - a[0];
  b[2] = c[2] - a[0];
  a[1] = c[3*1] - b[0];
  a[2] = c[3*2] - b[0];
  bool flg=true;
  FOR(j,1,3){
    FOR(i,1,3){
      val = c[j*3 + i] - b[i];
      //cout << i << " " << j << " " << c[j*3+i] << b[i] << " " <<  a[j] << val << endl;
      if(val != a[j]){
        flg = false;
      }
    }
  }
  if(flg){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}

int main(){
  //c1();
  //c5();
  //c6();
  //c7();
  //c8();
  c9();
  return 0;
}
