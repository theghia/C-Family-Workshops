/* Exercise 3 */

#include<stdio.h>

int main(void)
{
    /* part a */
    int x = 4;
    
    /* part b */
    printf ("Initial value of 'x': %d\n", x);
    
    /* part c */
    printf ("Memory address of 'x': %p\n", &x);
    
    /* part d */
    int *xptr = &x;
    
    /* part e */
    *xptr = 6;
    
    /* part f */
    printf("New value of 'x' (using xptr): %d\n", *xptr);
    
    /* part g */
    printf("Memory address of 'xptr': %p\n", xptr);
    
    return 0;
}
