#include "StdAfx.h"
#include "Assert.h"
#include "AboutAssert.h"


void aboutAssertParameterTypes(){
	expectThat("actual and expected need to be of the same type",3,3);
	expectThat("however, if they are not the same, expected is tried to be cast to the actual type.",3.0,3);
	expectThat("truncating information when casting to narrower type",3.1,3);
	expectThatNot("and not if casted to a wider type",3,3.1);
	expectThatNot("you won't get an Error for bad types","expected",42);
	//this causes a crash
	//expectThat("this is the error message you get when the cast failed",42,"expected");
	expectThat("thus, you can also compare c-strings with cpp-strings","cstring",string("cstring"));
}

void AboutAssert::meditate(){
	aboutAssertParameterTypes();
}