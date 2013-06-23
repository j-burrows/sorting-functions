/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	merge.h
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide a merge sort algorithm.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		April 8th 2013
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/

#ifndef MERGE_H
#define MERGE_H 1

#include <stdlib.h>
#include <string.h>

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	merge_sort
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Initiates the merge sort given only the list and length.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		list	The list that will be sorted.
 |				low		The start index for the current piece
 |				right	The end index for the current piece
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
extern void merge_sort(int list[], size_t list_len);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	m_sort
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Partitian a list into pieces and perform a merge sort on them.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		list	The list that will be sorted.
 |				left		The start index for the current piece
 |				right	The end index for the current piece
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
extern void m_sort(int list[], int left, int right);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	merge
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Sorts a piece of a list whos left and right halfs have been sorted.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		list	The list that will be sorted.
 |				left		The start index for the current piece
 |				right	The end index for the current piece
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
extern int merge(int list[], int left, int mid, int right);

#endif
