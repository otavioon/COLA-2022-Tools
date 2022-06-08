#include<bits/stdc++.h>

int main()
{

    std::vector<std::vector<int>> map(3,std::vector<int>(3));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cin>>map[i][j];
        }
    }
    bool res = false;
    std::vector<int> a(3);
    for(a[0] = 0;a[0] <= 100;a[0]++){
        for(a[1] = 0;a[1] <= 100;a[1]++){
            for(a[2] = 0;a[2] <= 100;a[2]++){
                bool flag = true;
                std::vector<int> b(3);
                for(int i=0;i<3;i++)b[i] = map[0][i] - a[0];
                for(int i=1;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(b[j] != map[i][j] - a[i])flag = false;
                    }
                } 
                //std::cout<<a[0]<<" : "<<a[1]<<" : "<<a[2]<<std::endl;
                //std::cout<<b[0]<<" : "<<b[1]<<" : "<<b[2]<<std::endl;
                if(flag)res = true;
            }
        }
    }
    std::cout << (res ? "Yes" : "No") << std::endl;
}