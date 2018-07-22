/*
  Credit 
       | -DevRaj |
*/
#include<stdio.h>
int display(int *p,int ii,int jj,int kk);

/*If you don't know then you will definitely ask what the hack is int (*p)[4][2] down below in show()
  well here, (*p)[][] is a pointer to a 2d array , means this 'p' pointing to the
  2d array. By writing p+1 will point to the next 2d array.
  If I write *(p+1) then it will point to the 0th row of the next 2d array.
  *(p+1) is same as *(p+1)+0. Again if I write *(*(p+1)+0) or *(*(p+1)+0)+0
  it will point or return the base address of the 1d array by adding 1 it will point to 
  the next element by writing this (*(*(p+1)+2)+0). And then it will give the integer value
  by *(*(*(p+1)+2)+0) this.
*/
int show(int (*p)[4][2],int ii,int jj,int kk)
{
	int *q; // Well, this will always hold the address of the variable containing integer value.
 
       //printf("%d\n",*(*(*(p+1)+2)+0)); // printing element directly by pointer to a 2d array variable : P
	printf("printing by show method : \n"); 
	for (int i = 0; i < ii; ++i)
	{
		for (int j = 0; j < jj; ++j)
		{
			q=p[i][j];  // Assigning the base address of the 1d array
			for (int k = 0; k < kk; ++k)
			{
				printf(" %d ", *(q+k));
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}

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
	/*passing base address of the 3d array and its corresponding sizes*/
	display(a,3,4,2);
	show(a,3,4,2);
}

int display(int *p,int ii,int jj,int kk)
{
    /*Well, Whether it is 1d, 2d or 3d all elements are being stored on the consecutive
	places means one after another, if you get the address of the starting element you 
	will catch all its preceding elements.This is what happening in this below printf statement.
	 eg: 	printf("%d\n",*(p+8)); 
	 Here , p is an integer pointer and it is pointing to the first element of the 3d array.
	Why because in calling statement in the main(), passing the address of the 3d array
	 eg : display(a,3,4,2); // Here 'a' containing the address of the 3d array. 
    */
	    printf("printing by display method : \n"); 
		for (int i = 0; i < ii; ++i)
		{	
			for (int j = 0; j <jj ; ++j)
			{
				for (int k = 0; k < kk; ++k)
				{
					printf("  %d  ", *(p+i*jj*kk+j*kk+k));   // code to print all the elements of the 3d array.
					/*here *(p+traverse 2d array+traverse row+traverse 1d array elements)*/
				}
				printf("\n");
			}
			printf("\n");
		}
}




