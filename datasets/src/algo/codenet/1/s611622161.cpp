#include <iostream>
using namespace std;
int main()
{
	int matrix[3][3];
  	int a, b;
  	for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 3; j++){
        	cin >> matrix[i][j];
        }
    }
  	a = matrix[1][0] - matrix[0][0];
  	if ((matrix[1][1] - matrix[0][1] != a) || (matrix[1][2] - matrix[0][2] != a)){
    	cout << "No";
      	return 0;
    }
  	b = matrix[2][0] - matrix[0][0];
  	if ((matrix[2][1] - matrix[0][1] != b) || (matrix[2][2] - matrix[0][2] != b)){
    	cout << "No";
      	return 0;
    }
  	cout << "Yes";
}	