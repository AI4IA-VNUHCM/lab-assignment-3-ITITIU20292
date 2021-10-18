/*
5. Write a function to move all positive element of an array upfront
Ex:
______________________________________
| Input: 2 -3 4 6 -7 9 8 -2          |
| Output: 2 4 6 9 8 -3 -7 -2         |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

void Ex5(int arr[], int n){
	//Your codes here
	int temp[n]; 
    int j = 0;
    for (int i = 0; i < n ; i++) 
        if (arr[i] >= 0 ) 
            temp[j++] = arr[i]; 
    if (j == n || j == 0) 
        return; 
    for (int i = 0 ; i < n ; i++) 
        if (arr[i] < 0) 
            temp[j++] = arr[i]; 
    memcpy(arr, temp, sizeof(temp));
	for (int i = 0; i < n; i++) 
       printf("%d ",arr[i]);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex5(testcase, argc);
	
	return 0;
}
