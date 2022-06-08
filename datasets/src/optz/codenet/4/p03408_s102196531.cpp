#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;


int main()
{
    int n,m;
    vector<string> s, t;
    string str;
    set<string> a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        a.insert(str);
        s.push_back(str);
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> str;
        a.insert(str);
        t.push_back(str);
    }
    int max_yen = 0;
    for(set<string>::iterator i=a.begin(); i!=a.end(); i++)
    {
        int yen = 0;
        for(int j=0;j<s.size();j++)
            if(s[j]==*i)
                yen++;
        for(int j=0;j<t.size();j++)
            if(t[j]==*i)
                yen--;
        if(yen > max_yen)
            max_yen = yen;
    }
    cout << max_yen;
    return 0;
}
