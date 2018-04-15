#include "sp_nim.c"

int check_win(int heap_num, int heaps[MAX_HEAPS]){
	int i; /* loop index */
	for(i = 0; i<heap_num; i++){
		if(heaps[i]) return 0;
		/* if any heap has non zero height then game is not over */
	}
	return 1;
	/* otherwise game is over */
}

int move(int heap_num, int heaps[MAX_HEAPS], int heap_index, int amount){
	/* check whether move is legal */
	if(heap_index >= heap_num || heap_index < 0) return 1;  /* heap index is illegal */
	if(amount <= 0 || amount > heaps[heap_index]) return 1; /* amount is illegal */
	heaps[heap_index] -= amount;
	return 0;
}

/*
returns nim sum of given game configuration
*/
int get_nim_sum(int heap_num, int heaps[MAX_HEAPS]){
	int nim_sum = 0;
	int i; /* loop index */
	for(i = 0; i<heap_num; i++){
		nim_sum ^= heaps[i];
	}
	return nim_sum
}

/*
changes given "out" array to contain index of first wining heap if there is any,
and amount that should be taken.
if there is a wining heap returns 0;
otherwise returns 1
*/
int get_wining_heap_move(int heap_num, int heaps[MAX_HEAPS], int out[2]){
	int i; /* loop index */
	int nim_sum = get_nim_sum(heap_num, heaps);
	for(i=0; i<heap_num; i++){
		if(heaps[i] ^ nim_sum < heaps[i]){ /* condition for wining heap */
			out[0]=i;
			out[1]= heaps[i] - (heaps[i] ^ nim_sum);
			return 0;
		}
	}
	/* if function did not return yet then no heap is winning */
	return 1;
}
/*
returns index of first nonempty heap.
*/
int get_nonempty_heap(int heap_num, int heaps[MAX_HEAPS]){
	int i; /* loop index */
	for(i=0; i<heap_num; i++){
		if(heaps[i]>0){
			return i;
		}
	}
}

void get_computer_move(int heap_num, int heaps[MAX_HEAPS], int out[2]){
	if(get_wining_heap_move(heap_num, heaps, out)){
		/* if failed to find wining heap: remove 1 from first nonempty heap */
		out[0] = get_nonempty_heap(heap_num, heaps);
		out[1] = 1;
	}
}
