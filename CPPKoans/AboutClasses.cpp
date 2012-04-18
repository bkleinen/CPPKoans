/*
 * AboutClasses.cpp
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#include "stdafx.h"
#include "AboutClasses.h"
#include "Assert.h"

class A {
public:
	A() {
	}
	virtual ~A() {
	}

	char method0() {
		return 'a';
	}
	char method1() {
		return 'a';
	}
	virtual char method2() {
		return 'a';
	}
};
class B: public A {
public:
	B() {
	}
	virtual ~B() {
	}
	char method1() {
		return 'b';
	}
	virtual char method2() {
		return 'b';
	}
};

void aboutMemberPolymorphism() {
	A a;
	B b;
	A c = b;

	expectThat("direct method call to a", 'a', a.method0());
	expectThat("b inherits method0 from a", 'a', b.method0());
	expectThat("direct method call to a", 'a', a.method1());
	expectThat("b overwrites method1", 'b', b.method1());
	expectThat("unless declared as virtual, methods are statically bound",
			'a', c.method1());
	expectThat("virtual method on b declared as B", 'b', b.method2());
	expectThat("virtual method on b declared as A", 'a', c.method2());

}
void AboutClasses::meditate() {
	aboutMemberPolymorphism();
}

