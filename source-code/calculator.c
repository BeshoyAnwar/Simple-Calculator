 /**********************************************************************************************************
 *
 * Module: calculator
 *
 * File Name: calculator.h
 *
 * Description: Source file for simple calculator deal with small integers(-128:127) and +,-,*,/ operations
 *
 **********************************************************************************************************/

#include "calculator.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
unsigned char static isOperand(char data){
	return data>='0'&&data<='9';
}

char static priority(char operator){
	switch(operator){
		case'+':
		case'-':
			return 0;
		case'*':
		case'/':
			return 1;
		default:
			return -1;
	}
}

unsigned char static infixTOPostfix(char* inExpression,char* outExpression){
	sstack* stack=(sstack*)createStack(strlen(inExpression));
	if(!stack)
		return 0;
	int length=-1;
	if(inExpression[0]=='-') outExpression[++length]='0';
	for(int i=0;i<strlen(inExpression);i++){
		if(isOperand(inExpression[i]))
			outExpression[++length]=inExpression[i];
		else if (inExpression[i] == '(')
			push(stack, inExpression[i]);
		else if (inExpression[i] == ')')
		{
			while (!isEmpty(stack) && top(stack) != '(')
				outExpression[++length] = pop(stack);
			if (!isEmpty(stack) && top(stack) != '('){
				deleteStack(stack);
				return 0;
			}
			else{
				pop(stack);
			}
		}
		else
		{
			while (!isEmpty(stack) && priority(inExpression[i]) <= priority(top(stack))){
				outExpression[++length] = pop(stack);
			}
			push(stack, inExpression[i]);
		}
	}
	while (!isEmpty(stack))
		outExpression[++length] = pop(stack);

	outExpression[++length] = '\0';
	deleteStack(stack);
	return 1;
}

unsigned char static evaluatePostfix(char* expression,char* result){
	sstack* stack=(sstack*)createStack(strlen(expression));
		if(!stack)
			return 0;
	for(int i=0;i<strlen(expression);i++){
		if(isOperand(expression[i]))
			push(stack,expression[i]-'0');
		else{
			char operand2=pop(stack);
			char operand1=pop(stack);
			int out;
			switch(expression[i]){
				case'+':
					out=operand1+operand2;
					break;
				case'-':
					out=operand1-operand2;
					break;
				case'*':
					out=operand1*operand2;
					break;
				case'/':
					out=operand1/operand2;
					break;
				default:
					return 0;
			}
			push(stack,out);
		}
	}
	if(!isEmpty(stack)){
		*result=pop(stack);
		return 1;
	}
	return 0;
}

unsigned char evaluateExpression(char* expression,char* result){
	char postfixExp[50];
	if(infixTOPostfix(expression,postfixExp)){
		if(evaluatePostfix(postfixExp,result)){
			return 1;
		}
	}
	return 0;
}
