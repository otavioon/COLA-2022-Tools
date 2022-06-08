#include<iostream>
#include<algorithm>

using namespace std;

int a[3000][2],i=0;

int main(){
    while(1){
        cin >>a[i][0] >>a[i][1];
        if(a[i][0] == 0 && a[i][1] == 0)break;
        sort(a[i],a[i]+2);
        i++;
    }
    for(int j=0;j<i;j++){
        cout << a[j][0] << " " << a[j][1] << endl;
    }
}
