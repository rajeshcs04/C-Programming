#include <stdio.h>
main() 
{
    double A, B, product;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &A, &B);  

    product = A*B;

    printf("Product = %0.2lf", product);
  
}

