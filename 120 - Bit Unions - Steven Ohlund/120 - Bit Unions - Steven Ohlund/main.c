#include <stdio.h>

struct bits_s
{
	unsigned char b0 : 1;
	unsigned char b1 : 1;
	unsigned char b2 : 1;
	unsigned char b3 : 1;
	unsigned char b4 : 1;
	unsigned char b5 : 1;
	unsigned char b6 : 1;
	unsigned char b7 : 1;
};


typedef union
{
	struct bits_s bits;
	unsigned char byte;
}reg_t;


int main()
{
	reg_t reg;

	reg.byte = 0;
	printf("0x%02X\n", reg.byte);

	reg.bits.b1 = 1;
	printf("0x%02X\n", reg.byte);

	reg.bits.b6 = 1;
	printf("0x%02X\n", reg.byte);

	reg.bits.b7 = 1;
	printf("0x%02X\n", reg.byte);

	reg.byte <<= 1;
	printf("0x%02X\n", reg.byte);

	reg.byte >>= 1;
	printf("0x%02X\n", reg.byte);

	return 0;
}
