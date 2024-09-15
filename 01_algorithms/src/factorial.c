#include "factorial.h"

int factr(int n)
{
	if (n <= 1) 
	{
		return 1;
	}
	else 
	{
		return n * factr(n - 1);
	}
}

int facti(int n)
{
	int result = n;
	while (--n > 0)
	{
		result *= n;
	}
	return result;
}