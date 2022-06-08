#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

void a()
{
   int n, a;
    cin >> n >> a;
    int t = n % 500;
    if(t <= a)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

void b()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int al, bob;
    al = bob = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            al += a[i];
        }else{
            bob += a[i];
        }
    }
    cout << al - bob << endl;
}

void c()
{
    vector<vector<int>> c(3, vector<int>(3));
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }
    if(c[0][1] - c[0][0] == c[1][1] - c[1][0])
    {
        if(c[1][1] - c[1][0] == c[2][1] - c[2][0])
        {
            if(c[0][2] - c[0][0] == c[1][2] - c[1][0])
            {
                if(c[1][2] - c[1][0] == c[2][2] - c[2][0])
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

void d()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    int white = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> s[i][j];
            if(s[i][j] == '.') white++;
        }
    }
    queue<vector<pair<int, int>>> queue1;
    vector<pair<int, int>> path;
    path.push_back({0, 0});
    queue1.push(path);
    vector<vector<bool>> flags(h, vector<bool>(w, true));
    while (!queue1.empty())
    {
        vector<pair<int, int>> current_path = queue1.front();
        queue1.pop();
        pair<int, int> current = current_path.back();
        if(current == make_pair(h - 1, w - 1))
        {
            cout << white - current_path.size() << endl;
            return;
        }
        //上
        if(current.first != 0)
        {
            if(s[current.first - 1][current.second] == '.' && flags[current.first - 1][current.second])
            {
                vector<pair<int, int>> new_path = current_path;
                new_path.push_back({current.first - 1, current.second});
                queue1.push(new_path);
                flags[current.first - 1][current.second] = false;
            }
        }
        //下
        if(current.first != h - 1)
        {
            if(s[current.first + 1][current.second] == '.' && flags[current.first + 1][current.second])
            {
                vector<pair<int, int>> new_path = current_path;
                new_path.push_back({current.first + 1, current.second});
                queue1.push(new_path);
                flags[current.first + 1][current.second] = false;
            }
        }
        //右
        if(current.second != w - 1)
        {
            if(s[current.first][current.second + 1] == '.' && flags[current.first][current.second + 1])
            {
                vector<pair<int, int>> new_path = current_path;
                new_path.push_back({current.first, current.second + 1});
                queue1.push(new_path);
                flags[current.first][current.second + 1] = false;
            }
        }
        //左
        if(current.second != 0)
        {
            if(s[current.first][current.second - 1] == '.' && flags[current.first][current.second - 1])
            {
                vector<pair<int, int>> new_path = current_path;
                new_path.push_back({current.first, current.second - 1});
                queue1.push(new_path);
                flags[current.first][current.second - 1] = false;
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    c();
    return 0;
}
