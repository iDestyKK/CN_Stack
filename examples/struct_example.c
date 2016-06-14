/*
 * Simple Struct example with CN_Queues
 *
 * CN_Queues hold any datatype as long as the size specified on initialization.
 * It also copies the bytes of the struct into the stack. Hence what we will
 * demonstrate in the code below.
 *
 * This application will make a struct, set some values, push it to the struct.
 * Afterwards, it will modify that struct, then push another copy. Then print
 * out the values of the two structs to stdout.
 */

#include <stdio.h>
#include <stdlib.h>

#include "../cn_stack.h"

typedef struct thing {
	int a, b;
} THING;

main() {
	CN_STACK stack = cn_stack_init(THING);

	THING a;
	a.a = 2;
	a.b = 3;

	cn_stack_push(stack, &a); //Push a copy of "a" to Queue

	//Update the original struct
	a.a++;
	a.b = a.a + a.b;
	cn_stack_push(stack, &a); //Push another copy of "a" to Queue

	THING* ii = 0; //Iterator
	while (!cn_stack_empty(stack)) {
		ii = cn_stack_front(stack);
		printf("STRUCT { A: %d, B: %d }\n", ii->a, ii->b);
		cn_stack_pop(stack);
	}

	cn_stack_free(stack);
}
