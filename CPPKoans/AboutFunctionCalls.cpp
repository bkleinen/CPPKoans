/*
 * AboutFunctionCalls.cpp
 *
 *  Created on: 15.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "AboutFunctionCalls.h"
#include "Assert.h"



void aboutPassingArrays(){


}

void someFunction1(int x, int y){
	x = 0;
	y++;
}
void aboutPassingByValue(){
	int a = 4711, b = 13;
	someFunction1(a,b);
	expectThat("if parameters are passed by value, ...",_____,a);
	expectThat("they are not changed in the outside context",_____,b);
}
// pass by reference: just add a &
void someFunction2(int x, int &y){
	x = 0;
	y++;
}
void aboutPassingByReference(){
	int a = 4711, b = 13;
	someFunction2(a,b);
	expectThat("if parameters are passed by reference, ...",_____,a);
	expectThat("they *are* changed in the outside context",_____,b);
}


void AboutFunctionCalls::meditate(){
	aboutPassingByValue();
	aboutPassingByReference();
	aboutPassingArrays();
}
