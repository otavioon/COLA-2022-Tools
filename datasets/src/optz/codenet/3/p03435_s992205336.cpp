#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int Map[3][3];
  bool flag=false;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin>>Map[i][j];
  for(int k=0;k<=Map[0][0];k++){
    int a[3]={};
    int b[3]={};
    a[0]=k;
    b[0]=Map[0][0]-k;
    bool flag2=false;
    for(int i=0;i<3;i++){
      if(i!=0)a[i]=Map[i][0]-b[0];
      if(a[i]<0){flag2=true;break;}
      for(int j=0;j<3;j++){
	if(i==0)b[j]=Map[i][j]-a[i];
	if(b[j]<0){flag2=true;break;}
	if((b[j]+a[i])==Map[i][j]){;
	}else{
	  flag2=true;
	  break;
	}
      }
      if(flag2)break;
    }
    if(flag2==false){
      flag=true;
      break;
    }
  }
  if(flag)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
