#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

#define REP(i,m,n)  for(i=m;i<n;i++)
#define N_MAX 100000

int main(){

    int n;
    int i;
    int a[N_MAX+1];
    int list[N_MAX+1];
    int temp1,temp2;
    set<int> s;
    set<int>::iterator ite;;
    int ans = 0;

    cin >> n;


    REP(i, 1, n+1){
        cin >> a[i];
        if (a[i] == 1){
            s.insert(i);
        }
    }

    temp2 = 1;
    REP(i, 0, n){
        ans++;
         temp1 = a[temp2];
         temp2 = temp1;
         if (temp2 == 2)
             break;
         ite = s.find(temp2);
         if (ite == s.end()){
             s.insert(temp2);
         }
         else {
             ans = -1;
             break;
         }
    }


    cout << ans << endl;

//    for (ite = s.begin(); ite != s.end(); ++ite)
//        cout << *ite << endl;




}