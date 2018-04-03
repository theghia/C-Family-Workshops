#include <stdio.h>

int factorialR(int aNumber)
{
 if (aNumber =< 0)
  return 1;
 else
  return aNumber * factorialR(aNumber -1);
}

int factorialL(int aNumber)
{
 if (aNumber =< 0)
	return 1;
 else
  {
   int num = 1;
   for( int i = 0; i< aNumber; i++)
   {
    num *= aNumber;
	aNumber -= 1;
   }
  }

}