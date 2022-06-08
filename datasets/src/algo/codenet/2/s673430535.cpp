//
//  main.cpp
//  PowersOfTwo2
//
//  Created by SZhang on 7/4/19.
//  Copyright © 2019 SZhang. All rights reserved.
//

#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
    int a,b,mx=0, counter=0;
    cin>>a;
    multimap<int,int> mp;
    for (int i=0;i<a;i++){
        cin>>b;
        mp.insert(pair<int,int>(b,a));
    }
    
    while (!mp.empty()){
        typeof mp.end() i=mp.end();
        i--;
        mx=(i)->first;
        mp.erase(i);
        int target=pow(2,(int)((log(mx)/log(2)+1)))-mx;
        typeof(mp.find(target)) it=mp.find(target);
        if(it!=mp.end()) {
            counter++;
            mp.erase(it);
        }
    }
    cout<<counter<<endl;
    return 0;
}
