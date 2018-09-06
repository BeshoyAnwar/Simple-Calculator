 /******************************************************************************
 *
 * Module: stack
 *
 * File Name: stack.c
 *
 * Description: Source file for stack structure of chars
 *
 *******************************************************************************/
#include "stack.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
sstack* createStack(unsigned int capacity){
	sstack* stack=(sstack*)malloc(sizeof(sstack));
	if(!stack)
		return NULL;
	stack->array=(char*)malloc(sizeof(char)*capacity);
	if(!(stack->array))
		return NULL;
	stack->top=-1;
	stack->capacity=capacity;
	return stack;
}

void deleteStack(sstack* stack){
	free(stack->array);
	free(stack);
}

void push(sstack* stack,char data){

	stack->array[++stack->top]=data;
}

char pop(sstack* stack){
	return stack->array[stack->top--];
}

char top(sstack* stack){
	return stack->array[stack->top];
}

unsigned char isEmpty(sstack* stack){
	return stack->top==-1;
}