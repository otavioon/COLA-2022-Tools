#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;





int main()

{

	int a[6]={0},b[6][6],x=1,j;

	for(a[1]=1;a[1]<6;a[1]++)

	{

		for(a[2]=1;a[2]<6;a[2]++)

		{

			for(a[3]=1;a[3]<6;a[3]++)

			{

				for(a[4]=1;a[4]<6;a[4]++)

				{

					for(a[5]=1;a[5]<6;a[5]++)

					{

						if(a[5]==2||a[5]==3)

							continue;

						if(a[1]==1||a[1]==2)

						{

							if(a[5]!=1)
							
							continue;

						}

						if(a[2]==1||a[2]==2)

						{

							if(a[2]!=2)

							continue;

						}

						if(a[3]==1||a[3]==2)

						{

							if(a[1]!=5)
							
							continue;

						}

						if(a[4]==1||a[4]==2)

						{							

							if(a[3]==1)

							continue;

						}

						if(a[5]==1||a[5]==2)

						{

							if(a[4]!=1)
							
							continue;

						}

						if(a[1]==a[2]||a[1]==a[3]||a[1]==a[4]||a[1]==a[5]||a[2]==a[3]||a[2]==a[4]||a[2]==a[5]||a[3]==a[4]||a[3]==a[5]||a[4]==a[5]||a[1]!=5||a[2]!=2||a[3]!=1||a[4]!=3||a[5]!=4)

							continue;

						cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5];

					}

				}

			}

		}

	}

	return 0;

}