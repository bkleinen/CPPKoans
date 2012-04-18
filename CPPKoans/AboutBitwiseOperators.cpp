#include "StdAfx.h"
#include "AboutBitwiseOperators.h"
#include "Assert.h"

void aboutShiftOperators(){
	unsigned short unsigned_one = 1; // a nice number on 2 byte going up to 65535
	short one = 1; // a nice number on 2 byte going up to : -32768 to 32767
	// 1 looks like this: 0000000000000001
	// now we can shift the set bit around
	unsigned short value = unsigned_one << 5;
	expectThat("shifting to the left is like multiplying with 2^n",32,value);
	value = value >> 1;
	expectThat("shifting to the right divides by two",16,value);
	value = value << 12;
	expectThat("careful though if out of bounds",0,value);
	short signed_value = one << 15;
	expectThat("and with the sign",-32768,signed_value);
	
	unsigned unsigned_integer = 1 << 15;
	expectThat("1 shifted 15 to the left is...",32768,unsigned_integer);
	short signed_short = short(unsigned_integer);
	expectThatRaw("and keep in mind things can happen when numbers are casted",short(-32768),signed_short);
}
void aboutOperators(){
	expectThat("| bitwise or",16,0|16);
	expectThat("& bitwise and",1,255&1);
	
	unsigned fifthbitset = 1<<5;
	expectThat("| can be used to set the nth bit",32,0|fifthbitset);
	expectThat("& can be used to determine if the 5th bit is set like so",true,((255>>5)&1 == 1));

	expectThat("^ bitwise XOR",6,3^5);
	expectThat("~ bitwise negation",-4,~3);
}
void AboutBitwiseOperators::meditate()
{
	aboutShiftOperators();
	aboutOperators();
}
