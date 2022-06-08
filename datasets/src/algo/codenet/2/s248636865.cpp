#include <iostream>
#include <cmath>
#include <set>
using namespace std;

#ifdef DEBUG
    #define IFD if(true)
#else
    #define IFD if(false)
#endif

int list(multiset<int, greater<int> > &s)
{
    cout << "list: ";
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    int N, tmp;
    int d = 0;
    multiset<int, greater<int> > s;
    int ans = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        s.insert(tmp);
    }

    while(!s.empty()) {
        IFD list(s);
        long v = *s.begin();
        s.erase(s.begin());
        IFD cout << "v: " << v << endl;
        long val = 1;
        while (val <= v) {
            val *= 2;
        }
        IFD cout << "val = " << val << endl;
        auto p = s.find(val - v);
        if(p != s.end()) {
            IFD cout << "hit = " << v << ", " << val - v << endl;
            s.erase(p);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
