/* Exercise 2 */

#include<stdio.h>
/*Use the commented out one in the vi editor when compiling away from the blue room and the one in quotations when using the gcc compiler in the blue room*/
/*#include<products.h>*/
#include "products.h"
#include<string.h>

int main (void)
{
    /* Test the product structure - part a */
    Product laptop;
    
    /* Populate product parameters */
    strcpy(laptop.description,"Laptop");
    laptop.code = 'A';
    laptop.price = 89.00;
    laptop.quantity = 1;
    
    /* Print product parameters */
    printf("Testing product structure...\n");
    printf("Product description: %s", laptop.description);
    printf("Product code: \n%c", laptop.code);
    printf("Product price: \n%0.2f", laptop.price);
    printf("Product quantity: \n%d\n\n", laptop.quantity);
    
    /* Create product list - part b - looong way */
    Product productList[3];
    
    strcpy(productList[0].description, "laptop");
    productList[0].code = 'A';
    productList[0].price = 499.99;
    productList[0].quantity = 1; 
    productList[0].count = 6;
    
    strcpy(productList[1].description, "carrying case");
    productList[1].code = 'B';
    productList[1].price = 12.5;
    productList[1].quantity = 2; 
    productList[1].count = 13;
    
    strcpy(productList[2].description, "pencils");
    productList[2].code = 'C';
    productList[2].price = 0.09;
    productList[2].quantity = 130; 
    productList[2].count = 7;
    
    /* Test product printing function - part c*/
    printf ("Testing product printing function...");
    int i = 0;
    
    for (i=0; i<3; i++)
    {
        if (i == 0)
            PrintProduct(productList[i], 1);
        else
            PrintProduct(productList[i], 0);
    }

    /* A different way to do it - part b with pointers */
    Product *p0, *p1, *p2;
    p0 = &productList[0];
    p1 = &productList[1];
    p2 = &productList[2];
    PopulateProduct(p1, "Laptop", 'A', 499.99, 1, 6);
    PopulateProduct(p0, "Carrying Case", 'B', 12.5, 2, 13);
    PopulateProduct(p2, "Pencils", 'C', 0.09, 130, 7);
    
    /* Test product array printing function - part c*/   
    printf ("\nTesting product array printing function...");
    
    /*One observation is that the calculation of the size of the array should not be done
    out of scope because some weird crap happens and I spend hours trying to debug...f*/
    PrintProductArray(productList, sizeof(productList)/sizeof(Product));
    
    return 0;
}
