#include "data.h"
#include <stdint.h>

uint32_t power_func(uint32_t base, uint8_t exp) {
	uint8_t i;
	uint32_t power=1;
	for (i=1; i<=exp; ++i) {
		power*=base;
	}
	return power;
}
	
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	int32_t temp;
	uint8_t length =0;
	uint8_t rem=0, i;
	char neg = 0;
	if (data<0 && base==10) {
		neg = 1;
		data = -data;
	}
	*ptr = '\0';
	++ptr;
	++length;
	if (data == 0) {
		*ptr='0';
		++ptr;
		++length;
		return 2;
	}
	while (temp>0) {
		rem=temp%base;
		temp/=base;
		*ptr = (rem>9)? (rem-10) + 'a' : rem + '0';
		++ptr;
		++length;
	}
	if (neg == 1) {
		*ptr='-';
		++ptr;
		++length;
	}
	for (i=0; i<(length/2); ++i) {
		temp=*(ptr+i);
		*(ptr+i)=*(ptr+length-1-i);
		*(ptr+length-1-i)=temp;
	}
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
	uint8_t i, lim=0, exp=0, temp;
	int32_t num = 0;
	char neg = 0;
	if (*ptr == '-') {
		neg = 1;
		lim=1;
	}
	ptr+=digits-2;
	for (i=digits-2; i>=lim; --i) {
		temp = *ptr > 'a'? *ptr-'a' : *ptr-'0';
		num += (power_func(base,exp) * temp);
		--ptr;
		++exp;
	}
	if (neg == 1)
		num = -num;
	return num;
}
