/*
 * Simple Integer Queue Test
 *
 * Tests CN_Queues and how they can be used to store integers and
 * print them out in the order that they were added to the stack.
 *
 * This application stores 0 through 9 in the stack and then
 * prints them out in that order by popping the stack.
 */

#include <stdio.h>
#include <stdlib.h>

#include "../cn_stack.h"

main() {
	//Initialize the Queue
	CN_STACK stack = cn_stack_init(int);

	int a;
	for (a = 0; a < 10; a++)
		cn_stack_push(stack, &a); //Pushes the value of "a" into the stack

	int b;
	while (!cn_stack_empty(stack)) {
		b = cn_stack_deref_front(stack, int); //Gets exact value of the front of the stack
		printf("%d\n", b);                    //Prints to stdout.
		cn_stack_pop(stack);                  //Pop the stack.
	}

	//Free the Queue
	cn_stack_free(stack);
}
