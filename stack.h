#include <stdio.h>
#include <stdlib.h>

#ifndef __STACK_H__
#define __STACK_H__

typedef struct {
	float *items;
	int top;
	int stsize;
} stack;

int init(stack *, int); // initializes stack

int isEmpty(stack *); 	// Check if it's empty

int isFull(stack *);	// Check if it's full

int push(stack *, float ); // Add on top of the stack

float pop(stack *); 	// Removes from the top of the stack, and returns the removed value

float peek(stack *);	// Check value of top of stack
 
#endif
