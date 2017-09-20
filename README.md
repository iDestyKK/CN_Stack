# CN_Stack
A C library that implements C++ Stacks in C.

Along with linked lists, stacks are among one of the simplest data structures. In C++, these are included in STL which you can use by using "#include &lt;stack&gt;". In C, you have to make it yourself.

Stacks are a LIFO (Last-In-First-Out) structure, meaning you can push back, and only pop back. In other words, you can add to the back of the stack, but you can only access the last element.

CN_Stack is a generic stack container that can hold any data of any size in it. This is because you specify the type while initiating the stack. All nodes created in that stack will be able to hold the number of bytes of the datatype specified. It is a dynamically resizable structure. All operations except for "cn_stack_clear" are constant time, making this an extremely fast and efficient library.

Full documentation at: <a href = "http://web.eecs.utk.edu/~ssmit285/lib/cn_stack/index.html">http://web.eecs.utk.edu/~ssmit285/lib/cn_stack/index.html</a></br>The documentation has details and examples on every single function in the library, as well as a guide comparing it to C++ Stacks.
