 /*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	merge.c
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
#include "merge.h"
#define MAX 1000

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	merge_sort
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
void merge_sort(int list[], size_t list_len){
	m_sort(list, 0, list_len-1);
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	m_sort
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
void m_sort(int list[], int left, int right){
	int mid;								//Determines the point of split
	
	if(left < right){
		mid = (left+right)/2;
		m_sort(list, left, mid);
		m_sort(list, mid+1, right);
		merge(list, left, mid, right);	//Sorts this peice once components are sorted.
	}
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	merge
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
int merge(int list[], int left, int mid, int right){
	int* temp;								//Holds the sorted values.
	int mid_point, low;						//Markes progess of the sort of each half.
	int i, k;								//Loop control.
	
	if( (temp = (int*) malloc((right+left+1)*sizeof(int))) == NULL){
		return -1;
	}
	
	low = left;
	i = left;
	mid_point=mid+1;
	
	/*	Adds elements from both sorted halfs, in order, until one half is exhausted.	*/
	while( (low<=mid) && (mid_point<=right)){
		if( list[low] <= list[mid_point]){
			temp[i] = list[low];
			low++;
		}
		else{
			temp[i] = list[mid_point];
			mid_point++;
		}
		i++;
	}
	
	/*	Finds the half that is not exhausted and adds its remains to the list.	*/
	if(low>mid){
		for(k=mid_point; k<=right;k++){
			temp[i] = list[k];
			i++;
		}
	}
	else{
		for(k=low; k<=mid; k++){
			temp[i] = list[k];
			i++;
		}
	}
	
	/*	The temp list is copied back into the original list.	*/
	for( k=left; k<=right; k++){
		list[k] = temp[k];
	}
	
	free(temp);
	temp = NULL;
	return 0;
}
