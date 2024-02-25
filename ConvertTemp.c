#include <stdio.h> 

float fahrenheittocelsius(float f) 
{ 
	return ((f - 32.0) * 5.0 / 9.0); 
} 

main() 
{ 
	float f = 40; 

	printf("Temperature in Degree Celsius : %0.2f", fahrenheittocelsius(f)); 
	
}
