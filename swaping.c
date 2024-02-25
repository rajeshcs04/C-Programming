#include<stdio.h>
main() 
{
  double first, second, temp;
  printf("Enter first number: ");
  scanf("%lf", &first);
  printf("Enter second number: ");
  scanf("%lf", &second);

  temp = first;

  first = second;

  second = temp;

  printf("\nAfter swapping, first number = %0.2lf\n", first);
  printf("After swapping, second number = %0.2lf", second);
  
}

