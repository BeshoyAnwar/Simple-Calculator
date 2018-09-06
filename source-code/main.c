 /******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description: Source file for application layer
 *
 *******************************************************************************/

#include "lcd.h"
#include "keypad.h"
#include "calculator.h"
int main(void)
{
	unsigned char key;
	signed char result;
	char expression[50];
	unsigned int i=0;
	unsigned equalFlag=0;
	LCD_init();
	LCD_displayStringRowColumn(0,0,"Simple");
	LCD_displayStringRowColumn(1,0,"Calculator");
	LCD_displayStringRowColumn(2,0,"Application");
	LCD_displayStringRowColumn(3,0,"By Beshoy Anwar");
	_delay_ms(500); /* Press time */
	LCD_clearScreen();
	LCD_goToRowColumn(0,0);

    while(1)
    {
		/* if any switch pressed for more than 250 ms it counts more than one press */
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		if(i%16==0)// go to the next row when the current one is full
		{
			LCD_goToRowColumn(i/16,0);
		}
		if(key==13)// clear key pressed
		{
			equalFlag=0;i=0;
			expression[0]='\0';
			LCD_clearScreen();
			LCD_goToRowColumn(0,0);
		}
		else if(key=='=')// = key pressed need to out the result of the entering expression
		{
			equalFlag=1;
			if(evaluateExpression(expression,&result)){
				LCD_displayCharacter(key);
				LCD_intgerToString(result);
			}
			else{

				LCD_displayString("Error");
			}
		}
		else// any key pressed except =,clear keys
		{
			if(equalFlag)// start a new expression => clear the screen first
			{
				equalFlag=0;i=0;
				expression[0]='\0';
				LCD_clearScreen();
				LCD_goToRowColumn(0,0);
			}
			if((key <= 9) && (key >= 0))
			{
				expression[i]=key+'0';
				LCD_intgerToString(key);
			}

			else{
				expression[i]=key;
				LCD_displayCharacter(key); /* display the pressed keypad switch */
			}

			expression[i+1]='\0';
			i++;
		}

		_delay_ms(250); /* Press time */
    }
}
