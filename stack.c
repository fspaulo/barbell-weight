#include "stack.h"

int init(stack *s, int size){
	s->items = malloc(sizeof(int)*size);
	if(s->items == NULL) {
		return 0;
	}
	s->top = -1;
	s->stsize = size;
	return 1;
}

int isEmpty(stack *s){
	if(s->top == -1)
		return 1;
	else 
		return 0;
}

int isFull(stack *s){
	if(s->top == s->stsize-1)
		return 1;
	else 
		return 0;
}

int push(stack *s, float data){
	if(isFull(s)){
		return 0;
	}
	else{
		s->top++;
		s->items[s->top] = data;
	}
	return 1;
}

float pop(stack *s){
	
	float valorRemovido;
	
	if(isEmpty(s))
		return 0;
	else{
		valorRemovido = s->items[s->top];
		s->top--;
	}
	return valorRemovido;
}

float peek(stack *s){
	float data;
	
	if(isEmpty(s))
		return 0;
	else
		data = s->items[s->top];
		
	return data;
}


