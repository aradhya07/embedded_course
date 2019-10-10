#include "data.h"
#include <stdio.h>
#include <stdint.h>
#include "platform.h"
uint32_t power_func(uint32_t base, uint8_t exp) {
	uint8_t i;
	uint32_t power=1;
	for (i=1; i<=exp; ++i) {
		power*=base;
	}
	return power;
}
	
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) 
{ 
	uint8_t i = 0; 
	uint8_t temp;	
	uint8_t isNegative = 0; 
	if (data == 0) 
	{ 
		ptr[i++] = '0'; 
		ptr[i] = '\0'; 
		return 2; 
	} 
	if (data < 0) 
	{ 
		isNegative = 1; 
		data = -data; 
	}  
	while (data != 0) 
	{ 
		int rem = data % base; 
		ptr[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
		data = data/base; 
	}  
	if (isNegative) 
		ptr[i++] = '-'; 

	ptr[i] = '\0'; 

	int start = 0; 
	int end = i-1; 
	while (start < end) 
	{  
		temp=*(ptr+start);
		*(ptr+start)=*(ptr+end);
		*(ptr+end)=temp;
		start++; 
		end--; 
	} 
	return (i+1); 
} 

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base) 
{ 
	int32_t res = 0, temp; 
	int32_t sign = 1;
	uint8_t i = 0;  
	if (ptr[0] == '-') {
		sign = -1; 
		i++;
	} 
	for (; ptr[i] != '\0'; ++i) {
		temp = *(ptr+i) > 'a'? *(ptr+i)-'a' : *(ptr+i)-'0'; 
		res = (res * base) + temp; 
	}
	return (sign * res); 
}
