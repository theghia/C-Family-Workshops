/* My sample code to show conditional inclusion */

#ifndef __CONDITIONALINCLUSION_H

    #define __CONDITIONALINCLUSION_H
    /* The code will then go here */

/* What this is essentially is saying is that if the macro __CONDITIONALINCLUSION_H */ 
/* has not been defined, then define it as so and execute the code. If it has been */
/* defined, then don't process anything up to #endif  */

/* This helps with not repetitively calling this header file and defining the structs */
/* and functions that could cause an error in your program if there states change when */
/* constantly called */ 

#endif