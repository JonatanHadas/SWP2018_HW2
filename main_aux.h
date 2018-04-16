/*
 * main_aux.h
 *
 *  Created on: Apr 15, 2018
 *      Author: User1
 */

#ifndef MAIN_AUX_H_
#define MAIN_AUX_H_

/*
gets heap sizes from standard input.
writes sizes into "int* sizes".
writes "int numHeaps" heaps.

returns 1 on success and 0 on failure.
*/
int inputHeapSizes(int* sizes, int numHeaps);

/*
gets heap number from standard input
and returns it.
"int maxNumHeaps" is maximum allowed number of heaps.

if fails prints error message and returns 0.
*/
int numHeaps(int maxNumHeaps);

/*
prints status:
turn number and heap sizes.

receives as parameters:
numHeaps: number of heaps
heaps: heap sizes in array
turn: number of turn
*/
void printStatus(int numHeaps, int* heaps, int turn);

/*
gets move from standard input
and writes it into "int out[2]".

first number describes heap index
second number describes amount

on failure writes {-2,-1}  (illegal move)
*/
void getMove(int move[2]);


#endif /* MAIN_AUX_H_ */
