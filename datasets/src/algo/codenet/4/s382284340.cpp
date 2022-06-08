#include <iostream>
using namespace std;
bool usable(int n, int a[]){
    bool flg=false;//0以外の数字が出てきているか
    int b[5];
    b[4]=n%10;
    b[3]=(n%100-b[4])/10;
    b[2]=(n%1000-b[3]*10-b[4])/100;
    b[1]=(n%10000-b[2]*100-b[3]*10-b[4])/1000;
    b[0]=(n%100000-b[1]*1000-b[2]*100-b[3]*10-b[4])/10000;
    for (int i=0; i<5; i++){
        if (flg=false && b[i]==0){//まだ０が出てなくて、今0
            continue;
        }
        else{
            flg=true;
            if (a[b[i]]==1){
                return false;
            }
        }
    }
    return true;
}



int main(){
    int n,k,x;
    cin >> n >> k;
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    for (int i=0; i<k; i++){
        cin >> x ;
        a[x]=1;//1ならば使用不可
    }
    
    while (usable(n,a)==false){
        n++;
    }
    cout << n <<endl;
}