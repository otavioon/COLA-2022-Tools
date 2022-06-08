#include <iostream>

using namespace std;

int main()
{
int grid[10];
for (int i=1; i <10;i++)cin>>grid[i];
if(grid[1]-grid[4]==grid[2]-grid[5]&&grid[2]-grid[5]==grid[3]-grid[6]&&grid[1]-grid[7]==grid[2]-grid[8]&&grid[2]-grid[8]==grid[3]-grid[9]&&grid[4]-grid[7]==grid[5]-grid[8]&&grid[5]-grid[8]==grid[6]-grid[9]){

    cout<<"Yes";
}
else cout <<"No";



    return 0;
}
