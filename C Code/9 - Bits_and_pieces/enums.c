/* Here is an example piece of code manipulating enums */

#include <stdio.h>

int main (void)
{
	enum dayOfWeek {
		SUN, /* Will have the default value of 0 */
		MON,
		TUE,
		WED,
		THU,
		FRI,
		SAT
	};
	
	enum dayOfWeek today = WED;
	
	printf("Day %d", today);
	
	/* Changing the assigned values */
	
	int toChange = MON | THU; /* bitwise or -> 00000101 */
	
	/* The integer should be 5 */
	printf("The assigned value has been changed to: %d", toChange);
	
	return 0;
}