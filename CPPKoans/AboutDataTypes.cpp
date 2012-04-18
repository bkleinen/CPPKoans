/*
 * AboutDataTypes.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "AboutDataTypes.h"
#include "Assert.h"
AboutDataTypes::AboutDataTypes() {

}
void aboutDataTypeSizes(){

	char decimal_point = '.';
	expectThat("char is on 1 byte",_____,sizeof(decimal_point));

	int number = 0;
	expectThat("integer is usually 32 bit",_____,sizeof(number));

	double flying_time = 2.9;
	expectThat("double takes 8 byte ",_____,sizeof(flying_time));

	bool tap = true;

	expectThat("boolean takes 1 byte ",_____,sizeof(tap));


}
void aboutSafeTypeConversions() {
	char c = 'a';
	int i1 = c;
	expectThat("converting char to int is save", ____, (char)i1);

	int i2 = 'a';
	char c2 = i2;
	expectThat("converting int to char works if value is small enough", ____, c2);
}
void aboutUnsafeTypeConversions() {
	int a = 128;
	char c3 = a; // doesn't fit in char - char is signed -128..127
	int b = c3;
	expectThat("int is cut off when pressed into a char", _____, b);


	double d = 47.11;
	int i = d;
	double converted = i;
	expectThat("double is cut off when assigned to int", ______,converted);

}

void AboutDataTypes::meditate() {
	aboutDataTypeSizes();
	aboutSafeTypeConversions();
	aboutUnsafeTypeConversions();

}

