#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


//  main.cpp
//  gosh
//  Created by ??? on 13-11-10.
//  Copyright (c) 2013? ???. All rights reserved.
/*
????row?col??????array????array[0][0]?????????????????????????
????
????????????????row?col?
???row??????col???????????????
??????row?col??0<row<100, 0<col<100?
????
????????????????????
????
3 4
1 2  4  7
3 5  8 10
6 9 11 12
 ????
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10
 11
 12*/

int main()
{
    int row,col,i,j,k,a[400][400]={0};
    cin>>row>>col;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }
    for(k=0;k<=row+col-1;k++)
    {
        for(i=0;i<2*k+1;i++)
        {
            if(a[i][k-i]!=0)
            {cout<<a[i][k-i]<<endl;}
        }
    }
    return 0;
}