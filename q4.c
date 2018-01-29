#include <stdio.h>

int main()
{
 unsigned short int intArray[10];
 
 unsigned short int i;
 
 unsigned short int j = 0;
 
 /*To populate the array with even numbers between 2 - 20 */
 for (i = 2; i < 21; i+=2)
  {
   intArray[j] = i;
   j++;
  }
 
 /*To get all of the values of intArray using the index notation*/
 for(i = 0; i<10; i++)
 {
  printf("The element at index %d of intArray is: %d\n", i, intArray[i]);
  printf("And the associated memory address is: %d\n", &intArray[i]);
  printf("\n");
 }
 
 /*An example*/
 int a[5] = {5,4,6,8,9};
 int k;
 for(k=0; k<5; k++)
 {
  int *x = &a[k];
  printf("Using pointers!! Element: %d\n", *x);
  printf("has the memory address: %d\n", x);
 }
 
 /*To get all of the values of the intArray using a pointer*/
 for(i=0; i<10; i++)
 {
  unsigned short int *ptr = &intArray[i];
  printf("(Pointers) At index %d, item is: %d\n", i, *ptr);
  printf("and can be found at the memory address: %d\n", ptr);
 }
 return 0;
}
