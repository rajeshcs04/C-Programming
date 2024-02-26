#include <stdio.h>
 
 main()
{
 
    int l, b;
    int Area, Perimeter;
    
    printf("Enter the value of length and breadth:");
    scanf("%d%d",&l,&b);
    Area = l * b;
    Perimeter = 2 * (l + b);
    printf("\nArea of rectangle is : %d", Area);
    printf("\nPerimeter of rectangle is : %d", Perimeter);
   
}
