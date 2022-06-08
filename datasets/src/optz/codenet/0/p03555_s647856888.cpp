#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s1[100],s2[100];
int main()
{
    int temp,ans;
    scanf("%s\n%s",s1,s2);
    for(int i=0; i<strlen(s1)-1; i++)
    {
        ans=i;
        for(int j=i+1; j<strlen(s1); j++)
        {
            if(s1[j]>s1[ans])
            {
                ans=j;
            }
        }
        if(ans!=i)
        {
            temp=s1[ans];
            s1[ans]=s1[i];
            s1[i]=temp;
        }
    }
    for(int i=0; i<strlen(s2)-1; i++)
    {
        ans=i;
        for(int j=i+1; j<strlen(s2); j++)
        {
            if(s2[j]>s2[ans])
            ans=j;
        }
        if(ans!=i)
        {
            temp=s2[ans];
            s2[ans]=s2[i];
            s2[i]=temp;
        }
    }
    if(strcmp(s1,s2)==0)
    {
        printf("YES\n");
        printf("This grid remains the same when rotated 180 degrees.\n");
    }
    else
    {
        printf("NO\n");
        printf("This grid does not remain the same when rotated 180 degrees.\n");
    }
    return 0;
}

