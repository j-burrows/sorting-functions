/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	radix.c
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/

#include "radix.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	radix_sort
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
int radix_sort(int list[], size_t list_len){
	int *b;									//List to hold compents during each pass.
	int m, exp;								//exp represents the current digit being proc.
	int i;									//Loop control.
	/*	Allocated memory and returns error value if unsuccessful.	*/
	if( (b=malloc(list_len*sizeof(int))) == NULL){
		return -1;
	}
	exp = 1;
	
	/*	The largest value in the list is found.	*/
	m=list[0];
	for( i=1; i < list_len; i++){
		if( m < list[i]){
			m = list[i];
		}
	}
	
	/* Passes are continued until 10^passnumber > largest number	*/
	while( (m/exp) > 0){
		int bucket[10] = {0};
		
		/*	The bucket is set to hold the amount of values that have which digit (with 
			respects to the current digit, determined by exp).	*/
		for( i=0; i<list_len; i++){
			bucket[list[i] / exp%10]++;
		}
		
		/*	Each bucket is set to hold the number of values with digits all digits equal and
			below it.	*/
		for( i = 1; i < 10; i++){
			bucket[i] += bucket[i-1];
		}
		
		/*	The numbers with each digit are placed into the temp list in order of their 
			current digit.	*/
		for( i = list_len-1; i >= 0; i--){
			b[--bucket[list[i]/exp%10]] = list[i];
		}
		
		/*	The temp list is copied into the given list.	*/
		for( i=0; i<list_len; i++){
			list[i] = b[i];
		}
		
		exp*=10;
	}
	
	return 0;
}
