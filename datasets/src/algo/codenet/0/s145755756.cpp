#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int K;
    cin >> str;
    cin >> K;
    char start1, start2, start3, end;
    start1 = str.at(0);
    if (str.length() >= 2)
        start2 = str.at(1);
    if (str.length() >= 3)
    {
        start3 = str.at(2);
    }
    end = str.at(str.length() - 1);
    long long count = 0, count1 = 1, count2 = 1;

    bool flag = false, flag_c = true;
    for (int i = 1; i < str.length(); ++i)
    {
        if (str.at(i - 1) == str.at(i))
        {
            if (flag_c)
                ++count1;
            continue;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (start1 == end)
    {
        for (int i = str.length() - 1; i > -1; --i)
        {
            if (str.at(i - 1) == str.at(i))
            {
                if (flag_c)
                    ++count2;
                continue;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }
    flag_c = (start1 == end);

    if (flag)
    {
        for (int i = 1; i < str.length(); ++i)
        {
            if (str.at(i - 1) == str.at(i))
            {
                ++count;
                str.at(i) = 'X';
            }
        }
        count *= K;
        if ((int)str.length() != 1)
        {
            if (str.at(str.length() - 2) != end)
            {
                if (start1 == str.at(str.length() - 1))
                {
                    if (flag_c && ((count1 + count2) % 2 == 1))
                    {
                    }
                    else{
                        count += K - 1;
                    }
                }
            }
        }
    }
    else
    {
        count = ((K + 1) / 2) * (str.length() / 2) + (K / 2) * ((str.length() + 1) / 2);
    }
    if (str.length() == 1)
    {
        count = K / 2;
    }
    cout << count << endl;
}