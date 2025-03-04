#include <stdio.h>


int main()
{
   int x;
   int y;

	x = 2;
	y = 2;
	if(x & y)
		printf("hey im here in and bitwise");
	if(x && y)
		printf("hey im here in and logical");
}
