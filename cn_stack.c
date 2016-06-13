/*
 * CN_Stack Library
 *
 * Version 1.0.0 (Last Updated 2016-06-11)
 *
 * Description:
 *     Stacks for C library. Implements the data structure with a main struct
 *     and a node struct with pointers to the top node only. Any datatype can
 *     be stored in a CN_Stack, just like C++ Stacks.
 *
 *     Changelog of library is located at the bottom of "cn_stack.h"
 *
 * Author:
 *     Clara Van Nguyen
 *
 * For documentation and details on every function in this library, visit the following URL:
 * http://web.eecs.utk.edu/~ssmit285/lib/cn_stack/index.html
 */

#include "cn_stack.h"

//Functions
//Initializer
CN_STACK new_cn_stack(cns_uint size) {
	CN_STACK stack = (CN_STACK) malloc(sizeof(struct cn_stack));
	stack->size = 0;
	stack->head = NULL;
	stack->elem_size = size;

	return stack;
}

//Add
void cn_stack_push(CN_STACK stack, void* ptr) {
	//Pushes an element to the end of the stack (Constant time implementation).
	CNS_NODE* data = __cn_stack_create_node(ptr, stack->elem_size);
	if (stack->size == 0)
		stack->head = (void *)data;
	else {
        data->next = stack->head;
        stack->head = data;
		//stack->back->next = (void *) data;
    }

	//This element is guaranteed to be the last element.
    if (stack->size == 0)
	   stack->back = data;

	//Increment the size
	stack->size++;
}

//Modify
void cn_stack_clear(CN_STACK stack) {
	//Clears the stack
	while (stack->size != 0)
		cn_stack_pop(stack);
}

void cn_stack_pop(CN_STACK stack) {
	//Removes the first entry from the stack.
	CNS_NODE* data = stack->head;

	if (stack->size == 1)
		stack->head == NULL;
	else
		stack->head = (void *) stack->head->next;

	__cn_stack_free_node(data);

	stack->size--;
}

//Get
void* cn_stack_front(CN_STACK stack) {
	return stack->head->data;
}

void* cn_stack_back(CN_STACK stack) {
	return stack->back->data;
}

cns_uint cn_stack_size(CN_STACK stack) {
	return stack->size;
}

cns_uint cn_stack_element_size(CN_STACK stack) {
	return stack->elem_size;
}

cns_byte cn_stack_empty(CN_STACK stack) {
	return (stack->size == 0);
}

//Deinitializer
void cn_stack_free(CN_STACK stack) {
	cn_stack_clear(stack);
	free(stack);
}

//Functions you won't use if you are sane
CNS_NODE* __cn_stack_create_node(void* ptr, cns_uint elem_size) {
	CNS_NODE* node = (CNS_NODE *) malloc(sizeof(struct cns_node));

	//Default Values
	node->next = NULL;
	node->data = (void *) malloc(elem_size);

	//Assign data to the struct with information from the stack class
	memcpy(node->data, ptr, elem_size);

	return node;
}

void __cn_stack_free_node(CNS_NODE* ptr) {
	free(ptr->data);
	free(ptr);
}
