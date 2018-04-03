/* Product library file */
#include<string.h>

typedef struct Product Product;

struct Product
{
    char description[30];
    char code;
    float price;
    int quantity;
    int count;
};

int PrintProduct(Product p, short printHeader)
{
    /*So printHeader must be any number except 0 to continue*/
    if (printHeader)
    {
    	/*Using left justified on all of the strings except "Count" allows the structure to be 		        readable*/
        printf("\n%-30s%-5s%-8s%-10s%9s\n", "Product Description", "Code", "Price", "Quantity", "Count" );
        printf("%-30s%-5s%-8s%-10s%9s\n", "-----------------------------", "----", "-------", "--------", "-----");
    }
    printf("%-30s%3c%9.2f%9d%8d\n", p.description, p.code, p.price, p.quantity, p.count);
    return 0;
}

/*Use the amount of arguments that you want!!*/
int PrintProductArray(Product p[], int len)
{
    int i = 0;
    for (i=0; i<len; i++)
    {
        if (i == 0)
	    /*This is smart and tidy. The first element of the list needs to be below the title and the dashes, */
		/* so the argument of 1 is given to evaluate as true in the PrintProduct function */
            PrintProduct(p[i], 1);
        else
            PrintProduct(p[i], 0);
    }
    return 0;
}

int PopulateProduct(Product *p, char desc[], char cod, float px, int q, int c)
{
    /*p is not a structure, it is a memory space to something that is a structure
    and so the "->" allows the compiler to look in that space and look for the different members*/
    strcpy(p->description, desc);
    p->code = cod;
    p->price = px;
    p->quantity = q; 
    p->count = c;
}
