#include <stdio.h>
 
int main () {

   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* what is the value in var? */
   printf("Value of var = %d\n", var );
   
   /*Go to the address in ptr and bring back the value of int stored there*/
   printf("Value available at *ptr = %d\n", *ptr );
   
   /*Go to the address in pptr and bring back the value of type int stored 
   there...but at pptr we have another pointer. So after going to the address
   in pptr, we go to the address int ptr and bring back the value of int 
   stored there*/
   printf("Value available at **pptr = %d\n", **pptr);
   
   /*Seeing where in memory the pointers are held*/
   printf("The location in memory where var is held = %d\n", &var);
   printf("The location in memory where ptr is held = %d\n", &ptr);
   printf("The location in memory where pptr is held = %d\n", &pptr);
   printf("\n");
   
   /*The legit value held at ptr is the location in memory where var is at*/
   printf("ptr = %d\n", ptr);
   
   /*The legit value held at pptr is the location in memory where ptr is at*/
   printf("pptr = %d\n", pptr);

   return 0;
}
