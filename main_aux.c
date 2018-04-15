/*
 ============================================================================
 Name        : SP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int inputHeapSizes(int* sizes, int numHeaps) {
	int scanCheck=0, i=0;
	printf("Enter the heap sizes:\n");
	for(i=0;i<numHeaps;i++){
		scanCheck=scanf("%d", (sizes+i));
		if(scanCheck==0 || sizes[i]<=0){
			printf("Error: the size of heap %d should be positive.\n", i+1);
			return 0;
		}
	}
	return 1;
}

int numHeaps(int maxNumHeaps){
	int scanCheck=0, numHeaps=0;
	printf("Enter the number of heaps:\n");
	scanCheck=scanf("%d", &numHeaps);
	if(scanCheck==0 || numHeaps<1 || numHeaps>maxNumHeaps){
		printf("Error: the number of heaps must be between 1 and 32.\n");
		return 0;
	}
	return numHeaps;
}
