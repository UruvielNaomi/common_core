#include "ft_printf.h"
#include <stdio.h>

int main() {
    int result;

    // Testing %c
    result = ft_printf("%c", 'A');
    printf("\nReturn value: %d\n", result);

    // Testing %s
    result = ft_printf("%s", "Hello, World!");
    printf("\nReturn value: %d\n", result);

    // Testing %x and %X
    result = ft_printf("%x", 255);
    printf("\nReturn value: %d\n", result);

    result = ft_printf("%X", 255);
    printf("\nReturn value: %d\n", result);

    // Testing %i and %d
    result = ft_printf("%i", 42);
    printf("\nReturn value: %d\n", result);

    result = ft_printf("%d", -42);
    printf("\nReturn value: %d\n", result);

    // Testing %u
    result = ft_printf("%u", 123);
    printf("\nReturn value: %d\n", result);

    // Testing %p
    int variable = 42;
    result = ft_printf("%p", (void*)&variable);
    printf("\nReturn value: %d\n", result);

    // Testing %%
    result = ft_printf("%%");
    printf("\nReturn value: %d\n", result);

    return 0;
}


/*
make       
cc -o test_main main.c ft_printf.c -L. -lftprintf
./test_main

cc: command for compiler.

-o test_main: gives the compiled executable the name 'test_main'.

main.c: This is the source file containing main function and the test cases.

ft_printf.c: The source file containing ft_printf function implementation and others.

-L.: tells compiler to look for libraries in the current directory -> libftprintf.a 

-lftprintf: This option specifies the name of the library to link against. 
The -l flag is followed by the library name, in this case, ftprintf. T
he linker searches for a file named libftprintf.a (as named in the makefile) in
the directories specified by the -L flag.


In your code, you might be using uintptr_t directly without explicitly using typedef. 
The reason for this is that uintptr_t is often defined as a typedef in the standard header 
file <stdint.h>

*/