#include "stdio.h"

extern int isGeometric(double[], int);

int main()
{
    double sequence[] = {
        1.0,
        2.0,
        4.0,
        8.0,
        16.0
    };
    printf("%i\n", isGeometric(sequence, 5));
	
	//Answer must be 1
	
    return 0;
}
