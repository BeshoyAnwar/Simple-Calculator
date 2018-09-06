 /**********************************************************************************************************
 *
 * Module: calculator
 *
 * File Name: calculator.h
 *
 * Description: Header file for simple calculator deal with small integers(-128:127) and +,-,*,/ operations
 *
 **********************************************************************************************************/
 
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "stack.h"
#include <string.h>

/*************************************************************************************
 *                      Functions Prototypes                                         *
 *************************************************************************************/
/*************************************************************************************
 *function name: isOperand						             *
 *function description: private function to determine if the char is a number or not *
 *function inputs: data=>the char needed to check                              	     *
 *function outputs: 1 if the char is a number,otherwise 0	 	             *
 *************************************************************************************/
unsigned char static isOperand(char data);

/*************************************************************************************
 *function name: priority							     *
 *function description: private function return the precedence of the operator	     *
 *function inputs: operator=>the char needed to know its priority                    *
 *function outputs: 0 if +,- 	1 if *,/	otherwise -1 for error checking	     *
 *************************************************************************************/
char static priority(char operator);

/*************************************************************************************
 *function name: infixTOPostfix			                                     *
 *function description: private function convert the the infix notation (3+5) to
			post fix notation (35+)                                      *
 *function inputs: inExpression=>pointer to char have the has address carry
		   infix expression                                                  *
 *function outputs: outExpression=>pointer to char have the has address carry
		    postfix expression 
		    unsigned char for error checking if no error return 1 
						     else return 0		     *
 *************************************************************************************/
unsigned char static infixTOPostfix(char* inExpression,char* outExpression);

/*************************************************************************************
 *function name: evaluatePostfix	                                             *     
 *function description: private function evalute the postfix expression using stack  *
 *function inputs: expression=>pointer to char have the has address carry
		   postfix expression                                                *
 *function outputs: result=>pointer to char have the has address carry result of the
		    expression														  
		    unsigned char for error checking if no error return 1 
					             else return 0		     *
 *************************************************************************************/
unsigned char static evaluatePostfix(char* expression,char* result);

/*************************************************************************************
 *function name: evaluateExpression	                                             *     
 *function description: public function evalute the infix expression with help of
			functions as infixTOPostfix,evaluatePostfix                  *
 *function inputs: expression=>pointer to char have the has address carry
		   infix expression                                                  *
 *function outputs: result=>pointer to char have the has address carry result of 
 		    the expression														  
		    unsigned char for error checking if no error return 1 
						     else return 0		     *
 *************************************************************************************/
unsigned char evaluateExpression(char* expression,char* result);


#endif /* CALCULATOR_H_ */
