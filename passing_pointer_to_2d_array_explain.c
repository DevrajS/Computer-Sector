#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a[3][4][2]={
					{
					{2,4},
					{7,8},
					{3,4},
					{5,6}
					},
					{
						{7,6},
						{3,4},
						{5,3},
						{2,3}
					},
					{
						{8,9},
						{7,2},
						{3,4},
						{5,1}
					}
	};
	
	// What i want to print is a[i][i][i] without square bracket
	// &a represent the whole 3d array
	// a+i  will represent  each 2d block
	//  *(a+i)+i represent each one dimensional array or row of the single block;
	//  *(*(a+i)+i)+i  will represent the address of the element of each 1d array or row
    // and finally
    //  *(*(*(a+i)+i)+i) will print the value

	printf(" printing value without square bracket %d \n printing with square bracket a[] = %d \n",*(*(*(a+1)+2)+1),a[1][2][1]);
	return 0;
}