#ifdef _KERNEL
#include <types.h>
#include <lib.h>
#else
 #include <stdlib.h>
 #include <string.h>
 #endif

/*
 * Standard C funciton: parse a string that represents a decimal integer.
 * Leading whitespace is allowed.
 * Also takes into account negative signed numbers.
 */
 
 int atoi(const char *s)
 {
	static const char digits[] = "0123456789";
	unsigned sum = 0;
	int sign = 1;
	
	/* skip whitespace */
	while(*s==' ' || *s=='\t')
	{
		s++;
	}
	
	/* Checking for sign */
	if(*s=='-')
	{
		sign = -1;
		s++
	}
	else
	{
		s++;		// this implies it is a positive number.
	}
	
	while(*s)
	{
		const char *location;
		unsigned digit;
		
		if(location==NULL)
		{
			break;
		}
		
		digit = (where
	