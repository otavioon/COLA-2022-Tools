#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;

int main(void){
    string n;
    int k;
    cin>>n>>k;
    set<int> d;
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        d.insert(tmp);
    }
    int min_num;
    for(int i=0;i<10;i++){
        if(d.find(i) == d.end()){
            min_num = i;
            break;
        }
    }


    int ans = 0;
    bool flag = 0;
    for (char nd :n){
        int a = nd-'0';
        if(flag == 1){
            ans = ans*10 + min_num;
            continue;
        }
        while(d.find(a) != d.end()){
            a ++;
            flag = 1;
            if(a>=10){
                ans ++;
                a -= 10;
            }
        }
        ans = ans*10 + a;
    }

    cout<<ans<<endl;

}