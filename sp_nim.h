#ifndef _SP_NIM_H
#define _SP_NIM_H

/*
maximum number of haeps
*/
#define MAX_HEAPS 32

/*
returns whether all heaps are empty (last player wins)
receives game configuration: number of heaps and array of heap heights.
*/
int check_win(int heap_num, int heaps[MAX_HEAPS]);

/*
implements a move
receives game configuration, heap index and amount taken,
if move is illeagal, returns 1 and does nothing.
if move is leagal, returns 0 and changes heap, accordingly
*/
int move(int heap_num, int heaps[MAX_HEAPS], int heap_index, int amount);

/*
recieves configuration
also receives array of 2 ints,
this array will be changed to {heap_index, amount}: the computers moves
*/
void get_computer_move(int heap_num, int heaps[MAX_HEAPS], int out[2]);

#endif
