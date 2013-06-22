#makefile
CC = gcc
WARNINGS = -Wall

all: SortFunctions.dll

SortFunctions.dll: mergesort.o quicksort.o radixsort.o
	$(CC) -shared -o SortFunctions.dll mergesort.o quicksort.o radixsort.o -Wl,--out-implib,libmessage.a
	
mergesort.o: mergesort.c mergesort.h
	$(CC) -c -DBUILD_DLL mergesort.c
	
quicksort.o: quicksort.c quicksort.h
	$(CC) -c -DBUILD_DLL quicksort.c
	
radixsort.o: radixsort.c radixsort.h
	$(CC) -c -DBUILD_DLL radixsort.c
	
clean:
	rm -rf *o SortFunctions.dll
