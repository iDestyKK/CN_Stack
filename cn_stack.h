/*
 * CN_Stack Library
 *
 * Version 1.0.0 (Last Updated 2016-06-05)
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

#ifndef __CN_STACK__
#define __CN_STACK__

#include <stdlib.h>
#include <string.h>

//Custom Types
typedef unsigned int       cns_uint;
typedef unsigned long long cns_u64;
typedef unsigned char      cns_byte;

//Structs
typedef struct cns_node {
	struct cns_node* next;
	void           * data;
} CNS_NODE;

typedef struct cn_stack {
	//Nodes holding data
	CNS_NODE* head,
		    * back;

	//Data needed in the structure
	cns_uint  size,
	          elem_size;
} *CN_STACK;

typedef CN_STACK     QUEUE;    //For you C++ people...
#define CNS_ITERATOR CNS_NODE* //My point still stands...

//Functions
//Initializer
CN_STACK  new_cn_stack          (cns_uint);

//Add
void      cn_stack_push         (CN_STACK, void*);

//Modify
void      cn_stack_clear        (CN_STACK);
void      cn_stack_pop          (CN_STACK);

//Get
void*     cn_stack_front        (CN_STACK);
void*     cn_stack_back         (CN_STACK);
cns_uint  cn_stack_size         (CN_STACK);
cns_uint  cn_stack_element_size (CN_STACK);
cns_byte  cn_stack_empty        (CN_STACK);

//Deinitializer
void      cn_stack_free         (CN_STACK);

//Functions you won't use if you are sane
CNS_NODE* __cn_stack_create_node(void*, cns_uint);
void      __cn_stack_free_node  (CNS_NODE*);

//Macros
#define cn_stack_init(type) \
	new_cn_stack(sizeof(type)) //For those who hate typing sizeof(...)i

#define cn_stack_deref(iterator, type) \
	*(type *)iterator

#define cn_stack_deref_front(CN_STACK, type) \
	*(type *)CN_STACK->head->data

#define cn_stack_deref_back(CN_STACK, type) \
	*(type *)CN_STACK->back->data

#endif

/***************************************\
    * ** ***    CHANGELOG    *** ** *
\***************************************/

/*
    2016-06-05 (1.0.0)
      - Started writing CN_Queue. Initial (And probably the only) Release.
*/
