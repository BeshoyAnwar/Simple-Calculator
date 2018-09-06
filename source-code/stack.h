 /******************************************************************************
 *
 * Module: stack
 *
 * File Name: stack.h
 *
 * Description: Header file for stack structure of chars
 *
 *******************************************************************************/
 
#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

/********** stack data type **********/
typedef struct {
	char *array;
	unsigned int capacity;
	int top;
}sstack;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
 
/*******************************************************************************
 *function name: createStack												   *
 *function description: create stack structure with given multiples of chars   *
 *function inputs: size=>number of chars in stack                              *
 *function outputs: pointer to the stack that has been created				   *
 *******************************************************************************/
sstack* createStack(unsigned int size);

/*******************************************************************************
 *function name: deleteStack												   *
 *function description: destroy the memory allocated for given stack pointer   *
 *function inputs: stack=>pointer to the needing destroyed stack               *
 *function outputs: none				  									   *
 *******************************************************************************/
void deleteStack(sstack* stack);

/*******************************************************************************
 *function name: push												  		   *
 *function description: add a new element on the top of the stack   		   *
 *function inputs: stack=>pointer to the needing stack ,data: the new element  *
 *function outputs: none				  									   *
 *******************************************************************************/
void push(sstack* stack,char data);

/*******************************************************************************
 *function name: pop												  		   *
 *function description: remove the top element of the stack   				   *
 *function inputs: stack=>pointer to the needing stack           			   *
 *function outputs: char carry the removed element data				  		   *
 *******************************************************************************/
char pop(sstack* stack);

/*******************************************************************************
 *function name: top												  		   *
 *function description: return the top element of the stack with no remove     *
 *function inputs: stack=>pointer to the needing stack           			   *
 *function outputs: char carry the top element data				  		   	   *
 *******************************************************************************/
char top(sstack* stack);

/*******************************************************************************
 *function name: isEmpty												  	   *
 *function description: determine if the stack is empty or not   			   *
 *function inputs: stack=>pointer to the needing stack           			   *
 *function outputs: 1 if empty,0 if not empty				  		  		   *
 *******************************************************************************/
unsigned char isEmpty(sstack* stack);



#endif /* STACK_H_ */






