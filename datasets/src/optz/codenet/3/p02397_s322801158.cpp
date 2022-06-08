#include <cstdio>
#include <deque>
#include <utility>

int main()
{
    std::deque< std::pair<short, short> > data;
    while(1)
    {
        short x, y;
        scanf("%hd %hd", &x, &y);
        if(x == 0 && y == 0) break;
        std::pair<short, short> p;
        p.first = (x < y) ? x : y;
        p.second = (x < y) ? y : x;
        data.push_back(p);
    }
    for(const auto &elem : data)
    {
        printf("%d %d\n", elem.first, elem.second);
    }
}
