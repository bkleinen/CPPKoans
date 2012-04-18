/*
 * AboutStrings.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 *
 *      see http://en.wikipedia.org/wiki/C_string_handling
 */
#include "stdafx.h"
#include "AboutStrings.h"
#include "Assert.h"
#include <iostream>
#include <cstring>

using namespace std;


void aboutCStrings(){
	char aString[] = "a string literal is a c-string, an array of chars.";
	// thus, aString is a pointer to char.
	char *x = aString;
	// and sizeof determines the size of the pointer!
	int pointerSize = sizeof(x);
	expectThat("the size of a pointer",4,pointerSize);

	// arrays in c don't store their length.
	// there is a method in cstring which determines it for strings looking for the terminating char.
	char anotherString[] ="0123456789";
	int stringLength = strlen(anotherString);
	expectThat("the length of the string is determined by looking for the null char",10,stringLength);
}
void aboutStringLiterals(){
	// internally, a c-string is an array of chars terminated by the null character \0
	// string literals - like "hello" - are short form for that.
	char hello1[] = {'h','e','l','l','o', '\0'};
	char hello2[] = "hello";
	expectThat("those strings are the same",true,(strcmp(hello1,hello2) == 0));
}
void aboutCPPStrings(){
	// C++ has a string library
	string s; // calls default constructor
	s = "big bang theory";

	int l = s.length();
	expectThat("length returns the length of the string",15,l);

	expectThat("elements can be accessed via [] as in arrays",'b',s[4]);
	string s1 = "hello";
	string s2 = "hello";
	expectThat("opposed to java, == works on C++ strings",true, s1 == s2);

	s[4] = 'B';

	expectThat("C++ strings are mutable.", string("big Bang theory"),s);
}
void aboutStringAssignmentCreatesACopy(){
	string s1 = "hello";
	string s2 = s1;
	s2[1] = 'a';
	expectThat("s1 is not changed",string("hello"),s1);
	expectThat("but s2 of course is changed",string("hallo"),s2);
}

string mutateString(string s){
	s[1] = 'a';
	return s;
}
void aboutStringsAsParametersBeingCopied(){
	string s1 = "hello";
	string s2 = mutateString(s1);
	expectThat("s1 is not changed by modification in function",string("hello"),s1);
	expectThat("but the return value s2 contains the change",string("hallo"),s2);
}
void mutateString(string *s_pointer){
	*s_pointer = "Hullu";
	//s*[1] = 'a';
}

void aboutPassingAsReferenceMutatesTheOriginalString(){
	string s1 = "hello";
	mutateString(&s1);
	expectThat("if passed by reference, the string is modified",string("Hullu"),s1);
}

void aboutTheConcatenationPitfall(){
	string s1 = "a ";
	expectThat("+ if overloaded to do string concatenation on C++ strings.",string("a cat"),s1+"cat");
	expectThat("can also be used with chars.",string("a c"),s1+'c');
	
	// however: "a "+"cat"; won't compile - they are both c-strings
	expectThatNot("this will compile, but not result in the expected",string("a c"),string("a "+'c'));
	
	char* s2 = "a123456789b123456789c";
	expectThat("in fact, it's a pointer manipulation II",string("6789c"),string(s2+16));
	
}

void AboutStrings::meditate() {
	aboutCStrings();
	aboutStringLiterals();
	aboutCPPStrings();
	aboutStringAssignmentCreatesACopy();
	aboutStringsAsParametersBeingCopied();
	aboutPassingAsReferenceMutatesTheOriginalString();
	aboutTheConcatenationPitfall();

}

