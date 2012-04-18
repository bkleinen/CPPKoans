/*
 * Assert.h
 *
 *  Created on: 14.03.2012
 *      Author: merlin
 */
#ifndef ASSERT_H_
#define ASSERT_H_

#define ____ 'x'
#define _____  42
#define ______  42.42
#define _______  "42"
#define ________  false
#define _________  true


#include <string>
#include <iostream>
#include <typeinfo>

#include "StopMeditating.h"
using namespace std;

template <class T>
void expectThatRaw (string message, T expected, T actual) {
	if (expected != actual) {
		reportUnmetExpectation(message,expected,actual);
	}
}
template <class T>
void expectThatNotRaw (string message, T expected, T actual) {
	if (expected == actual) 
		reportUnmetExpectation(message,expected,actual);
}

template <class T>
void expectThat (string message, T expected, T actual) {
	expectThatRaw(message,expected,actual);
}

template <class T,class U>
void expectThat (string message, T expected, U actual) {
	expectThatRaw(message+" (expected was casted to "+typeid(U).name()+")",U(expected),actual);
}

template <class T>
void expectThatNot (string message, T expected, T actual) {
	expectThatNotRaw(message,expected,actual);
}


template <class T,class U>
void expectThatNot (string message, T expected, U actual) {
	expectThatNotRaw(message+" (expected was casted to "+typeid(U).name()+")",U(expected),actual);
}

template <class T>
void reportUnmetExpectation(string message, T expected, T actual){
		cout << "Expectation Failed: " << message << endl;
		cout << "Expected: " << expected << ", but was: " << actual << endl;
		if (QUIT_ON_UNMET_EXPECTATION)
			throw StopMeditating();
}

#endif /* ASSERT_H_ */
