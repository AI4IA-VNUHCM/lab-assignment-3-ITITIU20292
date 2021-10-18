/*
3.	Input an array of n integers. Find the largest sorted sub array
(sorted array increasing/decreasing and has the largest number of elements)
Ex:
 _____________________________________________
| Input: 2 5 3 4 8 9 7 6 10                   |
| Output: Increasing 3 4 8 9 Decreasing 9 7 6 |
|_____________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex3(int in_arr[], int n){
	//Your codes here
	if(n==0){
		return;
	}
	int array1[n];
	array1[0]=1;
	for (int i=1;i<n;i++)
	{
		array1[i]=1;
		if(in_arr[i-1] <in_arr[i]){
			array1[i]=array1[i-1]+1;
		}
	}
	int array2[n];
	array2[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		array2[i]=1;
		if(in_arr[i]>in_arr[i+1])
		{
			array2[i]=array2[i+1]+1;
		}
	}

	int lbs_len=1;
	int begin=0,end=0;
	for(int i =0 ;i<n;i++)
	{
       if(lbs_len <array1[i]+array2[i] -1){
		   lbs_len=array1[i]+array2[i]-1;
		   begin= i -array1[i]+1;
		   end=i+array2[i] -1;
	   }
	}
	printf("Increasing [%d,%d]",begin,end);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex3(testcase, argc);
	
	return 0;
}
