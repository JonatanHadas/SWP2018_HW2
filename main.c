#include <stdio.h>
#include <stdlib.h>
#include "main_aux.h"
#include "sp_nim.h"

int main(void) {
	int heap_num, check=0, turn=0;
	int heapsSizes[MAX_HEAPS];
	int turnMove[2];
	heap_num=numHeaps(MAX_HEAPS);
	if(heap_num==0) return 0;
	check=inputHeapSizes(heapsSizes, heap_num);
	if(check==0) return 0;
	while(check_win(heap_num, heapsSizes)==0){
		turn++;
		if(turn%2==1){
			printf("Your turn: please enter the heap index and the number of removed objects.\n");
			getMove(turnMove);
			while(move(heap_num, heapsSizes, turnMove[0], turnMove[1])==1){
				printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
				getMove(turnMove);
			}
			printf("You take %d objects from heap %d.\n",turnMove[1]+1,turnMove[0]);
		}
		else{
			get_computer_move(heap_num, heapsSizes,turnMove);
			move(heap_num, heapsSizes, turnMove[0], turnMove[1]);
			printf("Computer takes %d objects from heap %d.\n",turnMove[1]+1,turnMove[0]);
		}
	}
	if(turn%2==1){
		printf("You win!\n");
	}
	else{
		printf("Computer wins!\n");
	}
	return 0;
}
