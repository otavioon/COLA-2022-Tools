#include <iostream>
#include <cmath>
#include <set>
using namespace std;

//#define DEBUG
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

    for(auto itr = s.begin(); itr != s.end(); itr++) {
        IFD cout << "itr: " << *itr << endl;
        IFD list(s);
        long v = *itr;
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
            itr = s.erase(itr);
            IFD cout << "d itr: " << *itr << endl;
            ans++;
            if(s.empty()) {
                break;
            }
            itr--;
        }
    }

    cout << ans << endl;

    return 0;
}
